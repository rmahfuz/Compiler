#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<string>
#include<algorithm>
#include"sym_table.cpp"

ScopeNode *cur_scope = NULL;
SymTable* global_table = new SymTable("GLOBAL"); 
ScopeNode* head_scope = new ScopeNode(global_table); 
std::string cur_func = "GLOBAL";
class LinkedListNode
{
	public:
		std::string val;
		LinkedListNode* next;
		LinkedListNode(std::string val_to_add = "nothing", LinkedListNode* next_to_add = NULL){
			val = val_to_add;
			next = next_to_add;
		}
		//~LinkedListNode(){delete val; delete next;}
};
class ASTNodeAddr //single node in linked list that stores address of child of an ASTNode
{
	public:
		void* val;  //ASTNode* in reality
		ASTNodeAddr* next;
		ASTNodeAddr(void* to_add){val = to_add; next = NULL;}//constructor
};
class CodeObject
{
	public:
		std::string type; //INT or FLOAT
		std::string temp_name; 
		std::string code;
		CodeObject(std::string type_to_add, std::string temp_name_to_add, std::string code_to_add){
			type = type_to_add;
			temp_name = temp_name_to_add;
			code = code_to_add;                                }
};
class ASTNode
{
	public:
		char* value, *node_type;
		ASTNodeAddr* children; //linked list of addresses of children
		ASTNode(char* value_to_add, char* type_to_add = ""){value = value_to_add; node_type = type_to_add; children = NULL;} //constructor
		void addChild(ASTNode* to_add);
		void printEntry(int indent = 0);
		ASTNode* searchForChild(char* to_search);
		CodeObject* generate_code();
};
void gen3AC(ASTNode* reqd_list);
std::string genTemp();
std::string genReg();
class LookupTableNode //linked list node with 2 strings as value. utility: lookup table to store reg corresponding to temp
{
	public:
		std::string key, val;
		LookupTableNode* next;
		LookupTableNode(std::string key_to_add = "nothing", std::string val_to_add = "nothing"){key = key_to_add; val = val_to_add; next = NULL;} //constructor
};
//ScopeNode *cur_scope = NULL, *head_scope = NULL;
ASTNode* assign_list = new ASTNode("","list of assignments");
long long int tmp_cnt = 1;
long long int reg_cnt = 0;
long long int label_cnt = 1;
LinkedListNode* head_code = new LinkedListNode();  //3AC code
LinkedListNode* cur_code = head_code;
LinkedListNode* head_asm = new LinkedListNode();
LinkedListNode* cur_asm = head_asm;
LookupTableNode* head_lut = new LookupTableNode(); //lookup table to map temp (from 3AC) to reg (in assembly)
LookupTableNode* cur_lut = head_lut;

LookupTableNode* addToLookupTable(std::string key_to_add, std::string val_to_add) //mapping temp (in 3AC) to reg (in assembly)
{
	if (cur_lut->key == "nothing")  //first time (head)
	{
		cur_lut->key = key_to_add;
		cur_lut->val = val_to_add;
		return cur_lut;
	}
	else
	{
		LookupTableNode* new_node = new LookupTableNode(key_to_add, val_to_add);	
		cur_lut->next = new_node;
		cur_lut = new_node;
		return new_node;
	}
}
std::string lookup_reg(std::string key_to_lookup)
{
	LookupTableNode* cur_node = head_lut;
	while (cur_node != NULL)
	{
		if (cur_node->key == key_to_lookup)
			return cur_node->val;
		cur_node = cur_node->next;
	}	
	return key_to_lookup;
}
void printLinkedList(LinkedListNode* head_node)
{
	LinkedListNode* cur_node = head_node;
	while (cur_node != NULL)
	{
		if (!(cur_node->val == ""))
			std::cout<<cur_node->val<<std::endl;
		cur_node = cur_node->next;
	}
	return;
}
std::string str_split(std::string to_split, int num = 1, char delim = ' ')
{
	int cnt = 0;
	std::string to_ret = "";
	for(int j = 0; j < num; j++)
	{
		to_ret = "";
		for (; (to_split[cnt] != delim) && to_split[cnt]; cnt++)
		{
			to_ret += to_split[cnt];
		}
		cnt++;
	}
	return to_ret;
}
std::string genReg()
{
	std::string to_ret(std::to_string(reg_cnt));
	reg_cnt += 1;
	to_ret = "r" + to_ret;
	return to_ret;
}
void add_instr(std::string to_add) //adds an asm instruction to the asm linked list
{
	if (cur_asm->val == "nothing") //first time, head
	{
		cur_asm->val = to_add;
	}
	else
	{
		LinkedListNode* new_node = new LinkedListNode(to_add);
		cur_asm->next = new_node;
		cur_asm = new_node;
	}
	return;
}
bool is_mem_ref(std::string op) //checks if op is a memory reference (returns true if op is a variable name or stack variable
{
	if ((op[0] == '$' && op[1] == 'T')|| ((int(op[0]) >= 48) && (int(op[0]) <= 57))) //if first letter is $ or digit
		return false;
	else if (op[0] == 'r')
	{
		for(int i = 2; i < op.length(); i++)
			if (op[i] < 48 || op[i] > 57) //op[i] is not a number
				return true;
		return false; //if it is r followed by all digits, it's a register
	}
	else
		return true;
}
std::string find_ret_type()  //find return type of a cur_func
{
	std::string to_ret = "dont know ret type of this func yet";
	SymTableChildNode* cur_child_node = head_scope -> val -> head_children_list;
	while (cur_child_node != NULL)
	{
		if (((SymTable*) cur_child_node->val) -> scope_name == cur_func)
		{
			to_ret = std::string(((SymTable*) cur_child_node -> val) -> ret_type)[0];
		}
		cur_child_node = cur_child_node->next_child;
	}
	//----------------------------------------
	return to_ret;
}
long long int find_num_args()  //find number of args of cur_func
{
	long long int arg_num = 0;
	SymTableChildNode* cur_child_node = head_scope -> val -> head_children_list;
	while (cur_child_node != NULL)
	{
		if (((SymTable*) cur_child_node->val) -> scope_name == cur_func)
		{
			Entry* cur_entry = ((SymTable*) cur_child_node -> val) -> head_entry;
			while (cur_entry != NULL)
			{
				if (cur_entry -> is_arg == true)
					arg_num += 1;
						
				cur_entry = cur_entry -> next_entry;
			}
		}
		cur_child_node = cur_child_node->next_child;
	}
	//----------------------------------------
	return arg_num;
}
std::string convert_to_param(std::string op, std::string func = cur_func)
//if op is a arg in func, it returns $6 for the first param, $7 for the second param, and so on. if op is not an arg, return the op itself
{
	std::string to_ret = op;
	long long int arg_num = 6;
	bool found = false;
	//----------------------------------------	
	SymTableChildNode* cur_child_node = head_scope -> val -> head_children_list;
	while (cur_child_node != NULL)
	{
		if (((SymTable*) cur_child_node->val) -> scope_name == func)
		{
			Entry* cur_entry = ((SymTable*) cur_child_node -> val) -> head_entry;
			while (cur_entry != NULL)
			{
				if ((cur_entry -> name == op) && (cur_entry -> is_arg == true))
				{
					to_ret = "$" + std::to_string(arg_num);
					arg_num += 1;
				}
				else 
				{
					if (cur_entry -> is_arg == true)
						arg_num += 1;
					if (cur_entry -> name == op)
						found = true;
				}
						
				cur_entry = cur_entry -> next_entry;
			}
		}
		cur_child_node = cur_child_node->next_child;
	}
	//----------------------------------------
	return to_ret;
}
void gen_asm(LinkedListNode* head_node) //parameter should be head_code
{
	Entry* cur_entry = head_scope->val->head_entry;
	std::string asm_in; //assembly instruction
	std::string op1, op2, res, new_reg, inst_to_add;
	//initialize variables
	while(cur_entry != NULL)
	{
		if (std::string(cur_entry->type) == "STRING")
		{
			asm_in = std::string("str ") + cur_entry->name + " " + cur_entry->value;
		}
		else
		{
			asm_in = std::string("var ") + std::string(cur_entry->name);
		}
		add_instr(asm_in);
		cur_entry = cur_entry->next_entry;
	}
	LinkedListNode* cur_node = head_node; //LinkedListNode where 3AC is stored (head_code)
	while (cur_node != NULL)
	{
		if (!(cur_node->val == ""))
		{
			std::string instr = str_split(cur_node->val);
			if (cur_node->val == "sys halt")
				add_instr(cur_node->val);
			else if (instr == "push" || instr == "pop")
			{
				op1 = str_split(cur_node->val, 2, ' ');
				//std::cout << "op1 = " << op1 << std::endl;
				if ((op1[0] == '$') && (op1[1] == 'T')) //if it is a temp
				{
					if (lookup_reg(op1) == op1)
					{
						std::string new_reg = genReg();
						addToLookupTable(op1, new_reg);
						op1 = new_reg;
					}
					else
						op1 = lookup_reg(op1); //look up the register corresponding to this temp
				}
				if ((instr == "push" && (cur_node->val).length() == 4) || (instr == "pop" && (cur_node->val).length() == 3)) //if instruction doesnt have anything after push or pop, let it be. dont add another operand
					op1 = "";
					//std::cout << "changed op1 is " << op1 << std::endl;
				add_instr(instr + " " +  op1);
			}
			else if (instr == "jsr" || instr == "link" || instr == "unlnk" || instr == "ret")
				add_instr(cur_node->val);
			else if (instr == "ADDI" || instr == "ADDF")
			{
				op1 = str_split(cur_node->val, 2, ' ');
				if ((op1[0] == '$') && (op1[1] == 'T')) //if it is a temp
					op1 = lookup_reg(op1); //look up the register corresponding to this temp
				op2 = str_split(cur_node->val, 3, ' ');
				if ((op2[0] == '$') && (op2[1] == 'T')) //if it is a temp
					op2 = lookup_reg(op2); //look up the register corresponding to this temp
				res = str_split(cur_node->val, 4, ' ');
				new_reg = genReg();
				std::string inst_to_add = (instr == "ADDI")? "addi " : "addr ";
				asm_in = "move " + op1 + " " + new_reg;
				add_instr(asm_in);
				asm_in = inst_to_add + " " + op2 + " " + new_reg;
				add_instr(asm_in);
				addToLookupTable(res, new_reg);
			}
			else if (instr == "SUBI" || instr == "SUBF")
			{
				op1 = str_split(cur_node->val, 2, ' ');
				if ((op1[0] == '$') && (op1[1] == 'T')) //if it is a temp
					op1 = lookup_reg(op1); //look up the register corresponding to this temp
				op2 = str_split(cur_node->val, 3, ' ');
				if ((op2[0] == '$') && (op2[1] == 'T')) //if it is a temp
					op2 = lookup_reg(op2); //look up the register corresponding to this temp
				res = str_split(cur_node->val, 4, ' ');
				new_reg = genReg();
				std::string inst_to_add = (instr == "SUBI")? "subi " : "subr ";
				asm_in = "move " + op1 + " " + new_reg;
				add_instr(asm_in);
				asm_in = inst_to_add + " " + op2 + " " + new_reg;
				add_instr(asm_in);
				addToLookupTable(res, new_reg);
			}
			else if (instr == "MULTI" || instr == "MULTF")
			{
				op1 = str_split(cur_node->val, 2, ' ');
				if ((op1[0] == '$') && (op1[1] == 'T')) //if it is a temp
					op1 = lookup_reg(op1); //look up the register corresponding to this temp
				op2 = str_split(cur_node->val, 3, ' ');
				if ((op2[0] == '$') && (op2[1] == 'T')) //if it is a temp
					op2 = lookup_reg(op2); //look up the register corresponding to this temp
				res = str_split(cur_node->val, 4, ' ');
				new_reg = genReg();
				std::string inst_to_add = (instr == "MULTI")? "muli " : "mulr ";
				asm_in = "move " + op1 + " " + new_reg;
				add_instr(asm_in);
				asm_in = inst_to_add + " " + op2 + " " + new_reg;
				add_instr(asm_in);
				addToLookupTable(res, new_reg);
			}
			else if (instr == "DIVI" || instr == "DIVF")
			{
				op1 = str_split(cur_node->val, 2, ' ');
				if ((op1[0] == '$') && (op1[1] == 'T')) //if it is a temp
					op1 = lookup_reg(op1); //look up the register corresponding to this temp
				op2 = str_split(cur_node->val, 3, ' ');
				if ((op2[0] == '$') && (op2[1] == 'T')) //if it is a temp
					op2 = lookup_reg(op2); //look up the register corresponding to this temp
				res = str_split(cur_node->val, 4, ' ');
				new_reg = genReg();
				std::string inst_to_add = (instr == "DIVI")? "divi " : "divr ";
				asm_in = "move " + op1 + " " + new_reg;
				add_instr(asm_in);
				asm_in = inst_to_add + " " + op2 + " " + new_reg;
				add_instr(asm_in);
				addToLookupTable(res, new_reg);
			}
			else if (instr == "WRITEI" || instr == "WRITEF" || instr == "WRITES")
			{
				op1 = str_split(cur_node->val, 2, ' ');
				std::string inst_to_add;
				if (instr == "WRITEI")
					inst_to_add = "writei";
				else if (instr == "WRITEF")
					inst_to_add = "writer";
				else if (instr == "WRITES")
					inst_to_add = "writes";
				asm_in = "sys " + inst_to_add + " " + op1;
				add_instr(asm_in);
			}
			else if (instr == "READI" || instr == "READF")
			{
				op1 = str_split(cur_node->val, 2, ' ');
				std::string inst_to_add = (instr == "READI")? "readi" : "readr";
				asm_in = "sys " + inst_to_add + " " + op1;
				add_instr(asm_in);
			}
			else if (instr == "STOREI" || instr == "STOREF")
			{
				op1 = str_split(cur_node->val, 2, ' ');
				res = str_split(cur_node->val, 3, ' ');
				if ((op1[0] == '$') && (op1[1] == 'T' )) //if it is a temp
					op1 = lookup_reg(op1); //look up the register corresponding to this temp
				if (is_mem_ref(op1) && is_mem_ref(res)) //if both are memory references
				{
					new_reg = genReg();
					asm_in = "move " + op1 + " " + new_reg;
					addToLookupTable(res, new_reg);
					add_instr(asm_in);
					asm_in = "move " + new_reg + " " + res;
				}
				else if ((res[0] == '$') && (res[1] == 'T'))
				{
					new_reg = genReg();
					asm_in = "move " + op1 + " " + new_reg;
					addToLookupTable(res, new_reg);
				}
				else
				{
					std::string op10 (1, op1[0]);
					std::string op11 (1, op1[1]);
					asm_in = "move " + op1 + " " + res;
				}
				add_instr(asm_in);
			}
			else if (instr.substr(0, 2) == "GT" || instr.substr(0, 2) == "GE" || instr.substr(0, 2) == "LT" || instr.substr(0, 2) == "LE" || instr.substr(0, 2) == "NE" || instr.substr(0, 2) == "EQ")
			{
				//std::cout << "from compop cur_func = " << cur_func << std::endl;
				std::string data_letter = "j";
				if (instr.substr(2, 1) == "F")
					data_letter = "r";
				if (instr.substr(2, 1) == "I")
					data_letter = "i";
				op1 = str_split(cur_node->val, 2, ' ');
				op2 = str_split(cur_node->val, 3, ' ');
				op1 = convert_to_param(op1);
				op2 = convert_to_param(op2);
				if ((op1[0] == '$') && (op1[1] == 'T')) //if it is a temp
					op1 = lookup_reg(op1); //look up the register corresponding to this temp
				if ((op2[0] == '$') && (op2[1] == 'T')) //if it is a temp
					op2 = lookup_reg(op2); //look up the register corresponding to this temp
				if (is_mem_ref(op1) && is_mem_ref(op2))
				{
					std::string reg_name = genReg();
					asm_in = "move " + op2 + " " + reg_name;
					add_instr(asm_in);
					asm_in = "cmp" + data_letter + " " + op1 + " " + reg_name;
				}
				else
					asm_in = std::string("cmp") + data_letter + " " + op1 + " " + op2; //cmpi op1 op2
				add_instr(asm_in);
				std::string comparator = str_split(cur_node->val, 1, ' ');
				char tmp[3] = {((char)(comparator[0] + 32)), ((char)(comparator[1] + 32))};
				asm_in = "j" + std::string(tmp) + " " + str_split(cur_node->val, 4, ' '); //jlt label
				add_instr(asm_in);
			}
			else if (instr == "LABEL")
			{
				if (str_split(cur_node -> val, 2, ' ').substr(0, 5) != "label")
				{
					cur_func = str_split(cur_node -> val, 2, ' ');
				}
				asm_in = "label " + str_split(cur_node->val, 2, ' ');
				add_instr(asm_in);
			}
			else if (instr == "JUMP")
			{
				asm_in = "jmp " + str_split(cur_node->val, 2, ' ');
				add_instr(asm_in);
			}
		}
		cur_node = cur_node->next;
	}
	//add_instr(std::string("sys halt"));
	add_instr(std::string("end"));
	return;
}
ASTNode* ASTNode::searchForChild(char* to_search)
{
	if (children == NULL)
		return NULL;
	else
	{
		ASTNodeAddr* cur_child = children;
		while(cur_child != NULL)
		{
			//printf("comparing existing val = %s with to_search = %s\n", (((ASTNode*)(((ASTNode*)(cur_child->val))->children->val))->value), to_search);
			if (strcmp((((ASTNode*)(((ASTNode*)(cur_child->val))->children->val))->value), to_search) == 0)
				return ((ASTNode*)(cur_child->val));
			cur_child = cur_child->next;
		}
	}
	return NULL;
}
void ASTNode::addChild(ASTNode* to_add)
{
	ASTNodeAddr* node_to_add = new ASTNodeAddr(to_add);
	if(children != NULL)
	{
		ASTNodeAddr* cur_child = children;
		while(cur_child->next != NULL)
			cur_child = cur_child->next;
		cur_child->next = node_to_add;
	}
	else
	{
		children = node_to_add;
	}
	return;
}
void ASTNode::printEntry(int indent /*=0*/)  //prints the ASTNode
{
	if (node_type == "READ" || node_type == "WRITE")
	{
		ASTNodeAddr* cur_id = (ASTNodeAddr*)value;	
		while (cur_id != NULL)
		{
			printf("%s ", ((ASTNode*)(cur_id->val))->value);
			cur_id = cur_id -> next;
		}

		printf(" (%s)\n", node_type);  //print the type of the ASTNode
	}
	else
		printf("%s (%s)\n", value, node_type);  //print the value of the ASTNode
	ASTNodeAddr* curChildAddr = children;
	while(curChildAddr != NULL)
	{
		for (int i = 0; i <= indent; i++)  //print tab (indent+1) number of times
			printf("    ");
		((ASTNode*)(curChildAddr->val))->printEntry(indent+1);
		//printf("\n");
		curChildAddr = curChildAddr->next;
	}
	return;
}
std::string genLabel()
{
	std::string to_ret(std::to_string(label_cnt));
	label_cnt += 1;
	to_ret = "label" + to_ret;
	return to_ret;
}
std::string genTemp()
{
	std::string to_ret(std::to_string(tmp_cnt));
	tmp_cnt += 1;
	to_ret = "$T" + to_ret;
	return to_ret;
}
void add_code(std::string to_add)  //add 3AC code
{
	if (cur_code->val == "nothing") //first time, head
	{
		cur_code->val = to_add;
	}
	else
	{
		LinkedListNode* new_node = new LinkedListNode(to_add);
		cur_code->next = new_node;
		cur_code = new_node;
	}
	return;
}
std::string complement(std::string op) //find complement of "GE" greater than equal to type operator
{
	if (op == "GT")
		return std::string("LE");
	else if (op == "GE")
		return std::string("LT");
	else if (op == "LT")
		return std::string("GE");
	else if (op == "LE")
		return std::string("GT");
	else if (op == "NE")
		return std::string("EQ");
	else if (op == "EQ")
		return std::string("NE");
	else
		return op + std::string(" is an invalid operator");
}
void initialize() //generate 3AC to call main
{
	add_code("push");
	//push parameters
	add_code("push r0");
	add_code("push r1");
	add_code("push r2");
	add_code("push r3");
	add_code("jsr main");
	add_code("sys halt");
	return;
}
int count_decl(std::string func_name) //counts number of declarations in the given function, look up from symbol table
{
	int num_decl = 0;
	SymTableChildNode* cur_child_node = head_scope -> val -> head_children_list;
	while (cur_child_node != NULL)
	{
		if (((SymTable*) cur_child_node->val) -> scope_name == func_name)
		{
			Entry* cur_entry = ((SymTable*) cur_child_node -> val) -> head_entry;
			while (cur_entry != NULL)
			{
				if (cur_entry -> is_arg == false)
					num_decl += 1;
						
				cur_entry = cur_entry -> next_entry;
			}
		}
		cur_child_node = cur_child_node->next_child;
	}
	//----------------------------------------
	return num_decl;
}
bool ChkIfVarIsLocalDeclInFunc(std::string var_name, std::string func_name) //checks if the variable is a local variable in the function
{
	SymTableChildNode* cur_child_node = head_scope -> val -> head_children_list;
	while (cur_child_node != NULL)
	{
		if (((SymTable*) cur_child_node->val) -> scope_name == func_name)
		{
			Entry* cur_entry = ((SymTable*) cur_child_node -> val) -> head_entry;
			while (cur_entry != NULL)
			{
				if ((cur_entry -> name == var_name) && (cur_entry -> is_arg == false))
					return true;
				cur_entry = cur_entry -> next_entry;
			}
		}
		cur_child_node = cur_child_node->next_child;
	}
	//----------------------------------------
	return false;
}
long long int GetVarNumInFunc(std::string var_name, std::string func_name) //finds out what number the variable is as a local declaration in that function
{
	long long int num = 0;
	SymTableChildNode* cur_child_node = head_scope -> val -> head_children_list;
	while (cur_child_node != NULL)
	{
		if (((SymTable*) cur_child_node->val) -> scope_name == func_name)
		{
			Entry* cur_entry = ((SymTable*) cur_child_node -> val) -> head_entry;
			while (cur_entry != NULL)
			{
				if ((cur_entry -> is_arg == false))
					num += 1;
				if (cur_entry -> name == var_name)
					return num;
				cur_entry = cur_entry -> next_entry;
			}
		}
		cur_child_node = cur_child_node->next_child;
	}
	//----------------------------------------
	return 0;
}
std::string process_tmp(std::string tmp)
{
	if (GetVarNumInFunc(tmp, cur_func) != 0) //check if local variable
		return std::string("$-" + std::to_string(GetVarNumInFunc(tmp, cur_func)));
	else
		tmp = convert_to_param(tmp); //if it is not a param, returns the same thing
	return tmp;
}
CodeObject* ASTNode::generate_code()
{
	//printf("\nin generate_code\n");
	//std::cout<<"Entered generate_code() for value "<<value<< " of type " << node_type << std::endl;
	CodeObject* to_ret = new CodeObject("doesnt matter", "doesnt matter", "doesnt matter");
	std::string code;
	if (strcmp(node_type, "RET_STMT")	== 0)
	{
		//std::string tmp_name = genTemp();
		//code = "ret";
		std::string to_ret = process_tmp(((ASTNode*)(children->val)) -> generate_code() -> temp_name);
		std::string where_to_return = "$";
		where_to_return += std::to_string((long long)(find_num_args() + 6));
		std::string func_ret_type = find_ret_type();
		code = "STORE" + func_ret_type + " " + to_ret + " " + where_to_return;
		add_code(code);
		add_code("unlnk");
		add_code("ret");
		//code = code + std::string(value) + " " + tmp_name;
		//to_ret = new CodeObject("INT", "doesnt matter", code);
	}
	if (strcmp(node_type, "INTLITERAL")	== 0)
	{
		std::string tmp_name = genTemp();
		code = "STOREI ";
		code = code + std::string(value) + " " + tmp_name;
		add_code(code);
		to_ret = new CodeObject("INT", tmp_name, code);
	}
	else if (strcmp(node_type, "FLOATLITERAL")	== 0)
	{
		std::string tmp_name = genTemp();
		code = "STOREF ";
		code = code + std::string(value) + " " + tmp_name;
		add_code(code);
		to_ret = new CodeObject("FLOAT", tmp_name, code);
	}
	else if (strcmp(node_type, "INT")	== 0)
	{
		to_ret = new CodeObject("INT", std::string(value), "");
	}
	else if (strcmp(node_type, "FLOAT")	== 0)
	{
		to_ret = new CodeObject("FLOAT", std::string(value), "");
	}
	else if (strcmp(node_type, "ADD") == 0)
	{
		std::string tmp_name = genTemp();
		CodeObject* left_child = ((ASTNode*)(children->val))->generate_code();
		CodeObject* right_child =   ((ASTNode*)(((ASTNodeAddr*)(children->next)->val)))->generate_code();
		if (left_child->type == "INT")
		{
			code = "ADDI ";
			code = code + process_tmp(right_child->temp_name) + " " + process_tmp(left_child->temp_name) + " " + tmp_name;
			add_code(code);
			to_ret = new CodeObject("INT", tmp_name, code);
		}
		else if (left_child->type == "FLOAT")
		{
			code = "ADDF ";
			code = code + process_tmp(right_child->temp_name) + " " + process_tmp(left_child->temp_name) + " " + tmp_name;
			add_code(code);
			to_ret = new CodeObject("FLOAT", tmp_name, code);
		}
	}
	else if (strcmp(node_type, "SUB") == 0)
	{
		std::string tmp_name = genTemp();
		CodeObject* left_child = ((ASTNode*)(children->val))->generate_code();
		CodeObject* right_child =   ((ASTNode*)(((ASTNodeAddr*)(children->next)->val)))->generate_code();
		if (left_child->type == "INT")
		{
			code = "SUBI ";
			code = code + process_tmp(left_child->temp_name) + " " + process_tmp(right_child->temp_name) + " " + tmp_name;
			add_code(code);
			to_ret = new CodeObject("INT", tmp_name, code);
		}
		else if (left_child->type == "FLOAT")
		{
			code = "SUBF ";
			code = code + process_tmp(left_child->temp_name) + " " + process_tmp(right_child->temp_name) + " " + tmp_name;
			add_code(code);
			to_ret = new CodeObject("FLOAT", tmp_name, code);
		}
	}
	else if (strcmp(node_type, "MUL") == 0)
	{
		std::string tmp_name = genTemp();
		CodeObject* left_child = ((ASTNode*)(children->val))->generate_code();
		CodeObject* right_child =   ((ASTNode*)(((ASTNodeAddr*)(children->next)->val)))->generate_code();
		if (left_child->type == "INT")
		{
			code = "MULTI ";
			code = code + process_tmp(right_child->temp_name) + " " + process_tmp(left_child->temp_name) + " " + tmp_name;
			add_code(code);
			to_ret = new CodeObject("INT", tmp_name, code);
		}
		else if (left_child->type == "FLOAT")
		{
			code = "MULTF ";
			code = code + process_tmp(right_child->temp_name) + " " + process_tmp(left_child->temp_name) + " " + tmp_name;
			add_code(code);
			to_ret = new CodeObject("FLOAT", tmp_name, code);
		}
	}
	else if (strcmp(node_type, "DIV") == 0)
	{
		std::string tmp_name = genTemp();
		CodeObject* left_child = ((ASTNode*)(children->val))->generate_code();
		CodeObject* right_child =   ((ASTNode*)(((ASTNodeAddr*)(children->next)->val)))->generate_code();
		if (left_child->type == "INT")
		{
			code = "DIVI ";
			code = code + process_tmp(left_child->temp_name) + " " + process_tmp(right_child->temp_name) + " " + tmp_name;
			add_code(code);
			to_ret = new CodeObject("INT", tmp_name, code);
		}
		else if (left_child->type == "FLOAT")
		{
			code = "DIVF ";
			code = code + process_tmp(left_child->temp_name) + " " + process_tmp(right_child->temp_name) + " " + tmp_name;
			add_code(code);
			to_ret = new CodeObject("FLOAT", tmp_name, code);
		}
	}
	else if (strcmp(node_type, "STORE") == 0) //adds required code
	{
		CodeObject* left_child = ((ASTNode*)(children->val))->generate_code();
		CodeObject* right_child =   ((ASTNode*)(((ASTNodeAddr*)(children->next)->val)))->generate_code();
		if (left_child->type == "INT")
		{
			code = "STOREI ";
			code = code + process_tmp(right_child->temp_name) + " " + process_tmp(left_child->temp_name);
			add_code(code);
			to_ret = new CodeObject("INT", process_tmp(left_child->temp_name), code);
		}
		else if (left_child->type == "FLOAT")
		{
			code = "STOREF ";
			code = code + process_tmp(right_child->temp_name) + " " + process_tmp(left_child->temp_name);
			add_code(code);
			to_ret = new CodeObject("FLOAT", process_tmp(left_child->temp_name), code);
		}
	}
	else if (strcmp(node_type, "READ") == 0)
	{
		ASTNodeAddr* cur_node = ((ASTNodeAddr*)(value));
		while(cur_node != NULL)
		{
			if (strcmp(((ASTNode*)(cur_node->val))->node_type, "INT") == 0)
			{	
				code = "READI " + process_tmp(std::string(((ASTNode*)(cur_node->val))->value));	
				add_code(code);
				to_ret = new CodeObject("INT", process_tmp(((ASTNode*)(cur_node->val))->value), code);
				//return to_ret;
			}
			else if (strcmp(((ASTNode*)(cur_node->val))->node_type, "FLOAT") == 0)
			{
				code = "READF " + process_tmp(std::string(((ASTNode*)(cur_node->val))->value));	
				add_code(code);
				to_ret = new CodeObject("FLOAT", process_tmp(((ASTNode*)(cur_node->val))->value), code);
				//return to_ret;
			}
			cur_node = cur_node->next;
		}
	}
	else if (strcmp(node_type, "WRITE") == 0)
	{
		ASTNodeAddr* cur_node = ((ASTNodeAddr*)(value));
		while(cur_node != NULL)
		{
			if (strcmp(((ASTNode*)(cur_node->val))->node_type, "INT") == 0)
			{	
				code = "WRITEI " + process_tmp(std::string(((ASTNode*)(cur_node->val))->value));	
				add_code(code);
				to_ret = new CodeObject("INT", process_tmp(((ASTNode*)(cur_node->val))->value), code);
				//return to_ret;
			}
			else if (strcmp(((ASTNode*)(cur_node->val))->node_type, "FLOAT") == 0)
			{
				code = "WRITEF " + process_tmp(std::string(((ASTNode*)(cur_node->val))->value));	
				add_code(code);
				to_ret = new CodeObject("FLOAT", process_tmp(((ASTNode*)(cur_node->val))->value), code);
				//return to_ret;
			}
			else if (strcmp(((ASTNode*)(cur_node->val))->node_type, "STRING") == 0)
			{
				code = "WRITES " + std::string(((ASTNode*)(cur_node->val))->value);
				add_code(code);
				to_ret = new CodeObject("STRING", ((ASTNode*)(cur_node->val))->value, code);
				//return to_ret;
			}
			cur_node = cur_node->next;
		}
	}
	else if ((strcmp(node_type, "GT") == 0) || (strcmp(node_type, "GE") == 0) || (strcmp(node_type, "LT") == 0) || (strcmp(node_type, "LE") == 0) || (strcmp(node_type, "NE") == 0) || (strcmp(node_type, "EQ") == 0))  //conditional operators
	{
		CodeObject* left_child = ((ASTNode*)(children->val))->generate_code();
		CodeObject* right_child =   ((ASTNode*)(((ASTNodeAddr*)(children->next)->val)))->generate_code();
		std::string data_type = std::string(left_child->type);
		std::string fresh_label = genLabel();
		code = complement(std::string(node_type)) + data_type[0] + " " + process_tmp(left_child->temp_name) + " " + process_tmp(right_child->temp_name) + " " + fresh_label; //gt op1 op2 label
		to_ret = new CodeObject(data_type, fresh_label, code);	
	}
	else if (strcmp(node_type, "IF") == 0)  //adds required code
	{
		CodeObject* cond = ((ASTNode*)(children->val))->generate_code();
		code = cond->code;
		add_code(cond->code);
		//CodeObject* decl = ((ASTNode*)(((ASTNodeAddr*)(children->next)->val)))->generate_code(); //not required because all declarations are in the beginning of asm file
		//CodeObject* stmt_list =   ((ASTNode*)(((ASTNodeAddr*)(children->next->next)->val)))->generate_code(); //let it add its own code, modify plz, this is 3rd, not 2nd
		gen3AC(((ASTNode*)(((ASTNodeAddr*)(children->next->next)->val)))); //rewriting above line
		std::string label2 = genLabel();
		add_code("JUMP " + label2);
		add_code("LABEL " + process_tmp(cond->temp_name));
		CodeObject* else_part =   ((ASTNode*)(((ASTNodeAddr*)(children->next->next->next)->val)))->generate_code();  //modify plz (this is 4th, not 2nd)
		add_code("LABEL " + label2);
		to_ret = new CodeObject("doesnt matter", "doesnt matter", "doesnt matter");	
	}
	else if (strcmp(node_type, "ELSE_PART") == 0) //adds required code
	{
		//CodeObject* decl = ((ASTNode*)(children->val))->generate_code(); //not required because all declarations are in the beginning of asm file
		//CodeObject* stmt_list =   ((ASTNode*)(((ASTNodeAddr*)(children->next)->val)))->generate_code(); //let it add its own code
		gen3AC(((ASTNode*)(((ASTNodeAddr*)(children->next)->val)))); //rewriting above line
		to_ret = new CodeObject("doesnt matter", "doesnt matter", "doesnt matter");	
	}
	else if (strcmp(node_type, "FOR_STMT") == 0)  //adds required code
	{
		((ASTNode*)(children->val))->generate_code(); //init_stmt
		std::string label1 = genLabel();
		add_code("LABEL " + label1); //label label1
		CodeObject* cond = ((ASTNode*)(((ASTNodeAddr*)(children->next)->val)))->generate_code();  //cond
		add_code(cond->code);
		//CodeObject* stmt_list =   ((ASTNode*)(((ASTNodeAddr*)(children->next->next)->val)))->generate_code(); //let it add its own code, modify plz, this is 3rd, not 2nd
		gen3AC(((ASTNode*)(((ASTNodeAddr*)(children->next->next->next->next)->val)))); //stmt_list
		((ASTNode*)(((ASTNodeAddr*)(children->next->next)->val)))->generate_code();  //incr_stmt
		add_code("JUMP " + label1);
		add_code("LABEL " + process_tmp(cond->temp_name));
		to_ret = new CodeObject("doesnt matter", "doesnt matter", "doesnt matter");	
	}
	//////////////////////////////
	else if (strcmp(node_type, "STMT_LIST") == 0) //adds required code
	{
		
	}
	else if (strcmp(node_type, "FUNC_BODY") == 0) //adds required code
	{
		gen3AC((ASTNode*)(((ASTNodeAddr*)(children->next)->val))); //call generate_code() for second child, the stmt_list
		to_ret = new CodeObject("doesnt matter", "doesnt matter", "doesnt matter");	
	}
	else if (strcmp(node_type, "FUNC_DECL") == 0) //adds required code
	{
		//if(strcmp((char*)((((ASTNodeAddr*)(children->next))->val)), "main") == 0)
		cur_func =  std::string((char*)((((ASTNodeAddr*)(children->next))->val)));
		//std::cout << "just assigned cur_func to " << cur_func << std::endl;
		add_code("LABEL " + std::string((char*)((((ASTNodeAddr*)(children->next))->val))));
		//long long int num_decl = count_decl((ASTNode*)(((ASTNodeAddr*)(children->next->next->next)->val))); //count number of declarations
		long long int num_decl = count_decl(std::string((char*)((((ASTNodeAddr*)(children->next))->val))));
		
		add_code("link " + std::to_string(num_decl));
		((ASTNode*)(((ASTNodeAddr*)(children->next->next->next)->val)))->generate_code();  //call generate_code() for fourth child, the func_body
		//add_code("unlnk"); //only happen at return stmt
		//add_code("ret");
		//third child: ASTNode
		ASTNodeAddr* cur_arg = ((ASTNode*)((children->next->next)->val))->children;
		while (cur_arg != NULL)
		{
			cur_arg = cur_arg->next;
		}
		to_ret = new CodeObject("doesnt matter", "doesnt matter", "doesnt matter");	
	}
	else if (strcmp(node_type, "FUNC_DECLARATIONS") == 0) //adds required code
	{
		ASTNodeAddr* cur_addr = children;
		while(cur_addr != NULL)
		{
			((ASTNode*)(cur_addr->val))->generate_code();
			cur_addr = cur_addr->next;
		}
		to_ret = new CodeObject("doesnt matter", "doesnt matter", "doesnt matter");	
	}
	else if (strcmp(node_type, "PGM_BODY") == 0) //adds required code
	{
		((ASTNode*)(children->next->val))->generate_code(); //call generate_code() for second child, the func_declarations
		to_ret = new CodeObject("doesnt matter", "doesnt matter", "doesnt matter");	
	}
	else if (strcmp(node_type, "FUNC_CALL") == 0)//adds required code, return temp name
	{
		add_code("push");//push space for ret val
		int arg_count = 0;
		if (children != NULL) //pushing arguments
		{
			ASTNodeAddr* cur_node = children;
			while (cur_node != NULL)
			{
				add_code("push " + process_tmp(std::string(((ASTNode*)(cur_node->val))->generate_code()-> temp_name)));
				arg_count++;
				cur_node = cur_node->next;
			}	
		}
		add_code("push r0"); //push registers onto stack
		add_code("push r1");
		add_code("push r2");
		add_code("push r3");
		add_code("jsr " + std::string(value));
		add_code("pop r3");
		add_code("pop r2");
		add_code("pop r1");
		add_code("pop r0");
		for(int i = 0; i < arg_count; i++) //popping arguments
			add_code("pop");
		std::string tmp_name = genTemp();
		add_code("pop " + tmp_name);
		std::string func_ret_type = std::string(head_scope->val->findRetType(value));
		to_ret = new CodeObject(func_ret_type, tmp_name, "code doesnt matter");
	}
	return to_ret;
}
void freeList(LinkedListNode* head)
{
	LinkedListNode* cur = head;
	while (cur != NULL)
	{
		LinkedListNode* tmp = cur;
		cur = cur->next;
		delete tmp;
	}
	return;
}
void gen3AC_stmt(ASTNode* candidate)
{
	candidate -> generate_code();
	return;
}
void gen3AC(ASTNode* reqd_list)
{
	//freeList(head_code);
	//head_code = new LinkedListNode();
	//cur_code = head_code;
	ASTNodeAddr* cur_addr = reqd_list->children;	
	while (cur_addr != NULL)
	{
		((ASTNode*)(cur_addr->val))->generate_code();
		cur_addr = cur_addr -> next;
	}
	return;
}
/*
int main()
{
	ASTNode* a = new ASTNode("*");
	ASTNode* x = new ASTNode("x");
	ASTNode* y = new ASTNode("y");
	ASTNode* z = new ASTNode("z");
	ASTNode* twelve = new ASTNode("12", "int");
	a->addChild(x);
	a->addChild(y);
	a->addChild(new ASTNode("are", "word"));
	a->addChild(new ASTNode("you", "word"));
	ASTNode* b = new ASTNode("*");
	b->addChild(z);
	b->addChild(twelve);
	b->addChild(new ASTNode("how"));
	ASTNode* c = new ASTNode("+");
	c->addChild(a);
	c->addChild(b);
	
	printf("----------------------------------\n");
	a->printEntry();
	printf("----------------------------------\n");
	b->printEntry();
	printf("----------------------------------\n");
	c->printEntry();
	
	//ASTNode a("+");
	//a.printEntry();
	return 0;
}
*/

