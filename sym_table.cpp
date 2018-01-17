#include<stdio.h>
//#include<string>
class Entry  //node for linked list of entries in a symbol table
{
	public:
		char *name, *type, *value;
		bool is_arg;
		Entry* next_entry;
		Entry(char* name_to_set, char* type_to_set, char* value_to_set = "", bool is_arg_to_set = false);  //constructor

		//Entry(){next_entry = NULL;} //constructor
		void addID(char* name_to_add, char* type_to_add);
		void addValue(char* value_to_add);
		void printEntry(bool printFunc = false);
};
class SymTableChildNode //single node to store address of child of SymTable in a linked list
{
	public:
		void* val; //value that the node is planning to store
		SymTableChildNode* next_child; //pointer to next node
		SymTableChildNode(void* to_add){val = to_add; next_child = NULL;} //constructor
};
class SymTable  //symbol table for a particular scope
{
	public:
		bool invalid;
		int block_num;
		char* scope_name;
		char* ret_type; //return type of function
		Entry* head_entry; //head of a linked list of entries	
		SymTableChildNode* head_children_list;  //head of list of children
		SymTable(char* scope_name_to_set, int block_num_to_set = 0, char* ret_type_to_set = ""); //constructor
		Entry* addEntry(char* name, char* type, char* value = "", bool is_arg = false);
		SymTableChildNode* addChild(SymTable* to_add);
		void printTable();
		void printChildList();
		void printAllInScope(); //prints all variables in scope (in this symbol table as well as in child symbol tables)
		bool checkExists(char* id, char* type); //checks if an entry like this already exists
		char* findType(char* id); //finds type given id
		char* findRetType(char* funcName); //finds return type of a function given funcName
};
class ScopeNode  //node for linked list of scopes
{
	public:
		SymTable* val;
		ScopeNode *next_scope, *prev_scope;
		ScopeNode(SymTable* val_to_set, ScopeNode* prev_scope_to_set = NULL){val = val_to_set; next_scope = NULL; prev_scope = prev_scope_to_set;} //constructor
};
class IdListType
{
	public:
		int count; //stores number of IDs
		float* id_list; 
};
char* SymTable::findType(char* id)
{
	char* to_ret = NULL;
	Entry* cur_entry = head_entry;
	//check all of its own entries
	while(cur_entry != NULL && to_ret == NULL)
	{
		//printf("cur_entry->type = %s\t", cur_entry->type);
		if (strcmp(cur_entry->name, id) == 0)
			to_ret = cur_entry->type;
		cur_entry = cur_entry->next_entry;
	}	
	//check all of its children's entries
	SymTableChildNode* cur_child = head_children_list;
	while(cur_child != NULL && to_ret == NULL)
	{
		to_ret = ((SymTable*) cur_child->val)->findType(id);
		cur_child = cur_child->next_child;
	}
	//printf("scope_name = %s, id_to_find = %s, to_ret = %s\n", scope_name, id, to_ret);
	return to_ret;
}
/*
char* SymTable::findRetType(char* id)
{
	char* to_ret = NULL;
	Entry* cur_entry = head_entry;
	//check all of its own entries
	while(cur_entry != NULL && to_ret == NULL)
	{
		//printf("cur_entry->type = %s\t", cur_entry->type);
		if (strcmp(cur_entry->name, id) == 0)
			to_ret = cur_entry->type;
		cur_entry = cur_entry->next_entry;
	}	
	//check all of its children's entries
	SymTableChildNode* cur_child = head_children_list;
	while(cur_child != NULL && to_ret == NULL)
	{
		to_ret = ((SymTable*) cur_child->val)->findType(id);
		cur_child = cur_child->next_child;
	}
	//printf("scope_name = %s, id_to_find = %s, to_ret = %s\n", scope_name, id, to_ret);
	return to_ret;
}
*/
bool SymTable::checkExists(char* id, char* type)
{
	bool exists = false;
	Entry* cur_entry = head_entry;
	//check all of its own entries
	while(cur_entry != NULL && exists == false)
	{
		if (strcmp(cur_entry->name, id) == 0 && strcmp(cur_entry->type, type) == 0)
			exists = true;
		cur_entry = cur_entry->next_entry;
	}	
	//check all of its children's entries
	SymTableChildNode* cur_child = head_children_list;
	while(cur_child != NULL && exists == false)
	{
		if (((SymTable*) cur_child->val)->checkExists(id, type) == true)
			exists = true;
		cur_child = cur_child->next_child;
	}
	return exists;
}
void SymTable::printAllInScope()
{
	if (invalid == false)
	{
		printTable();
		SymTableChildNode* cur_child_node = head_children_list;
		while (cur_child_node != NULL)
		{
			printf("\n");
			((SymTable*) cur_child_node->val) -> printAllInScope();
			cur_child_node = cur_child_node->next_child;
		}
	}
	return;
}
char* SymTable::findRetType(char* funcName)
{
	char* to_ret = "funcNameNotFound";
	if (invalid == false)
	{
		SymTableChildNode* cur_child_node = head_children_list;
		while (cur_child_node != NULL)
		{
			if (std::string(((SymTable*) cur_child_node->val)->scope_name) == std::string(funcName))
				to_ret = ((SymTable*)cur_child_node->val)->ret_type;
			cur_child_node = cur_child_node->next_child;
		}
	}
	return to_ret;
}
void SymTable::printChildList()
{
	printf("Printing child Symbol tables of Symbol table: %s\n", scope_name);
	SymTableChildNode* cur_child_node = head_children_list;
	while (cur_child_node != NULL)
	{
		printf("child is table of scope: %s\n", ((SymTable*) cur_child_node->val)->scope_name);
		cur_child_node = cur_child_node->next_child;
	}
	return;
}
SymTable::SymTable(char* scope_name_to_set, int block_num_to_set ,char* ret_type_to_set) //constructor
{
	invalid = false;
	block_num = block_num_to_set;
	scope_name = scope_name_to_set;
	ret_type = ret_type_to_set;
	head_entry = NULL;
	head_children_list = NULL;
}
Entry* SymTable::addEntry(char* name, char* type, char* value /*= ""*/, bool is_arg /*=false*/) //returns the added entry
{
	if (invalid == false && checkExists(name, type) == true)
	{
		printf("DECLARATION ERROR %s\n", name);
		invalid = true;
		return NULL;
	}

	Entry* new_entry = new Entry(name, type, value, is_arg);
	if (head_entry == NULL)
	{
		head_entry = new_entry;
	}
	else
	{
		Entry* cur_entry = head_entry;
		while (cur_entry->next_entry != NULL)
		{
			cur_entry = cur_entry->next_entry;
		}
		cur_entry->next_entry = new_entry;
	}
	return new_entry;
}
SymTableChildNode* SymTable::addChild(SymTable* to_add) //returns the added child address storage node
{
	SymTableChildNode* new_child_node = new SymTableChildNode(to_add);
	if (head_children_list == NULL)
	{
		head_children_list = new_child_node;
	}
	else
	{
		SymTableChildNode* cur_child_node = head_children_list;
		while (cur_child_node->next_child != NULL)
		{
			cur_child_node = cur_child_node->next_child;
		}
		cur_child_node->next_child = new_child_node;
	}
	return new_child_node;
}
void SymTable::printTable()
{
	if (std::string(ret_type) != "")
		printf("%s ", ret_type);
	if (block_num == 0)
		printf("Symbol table %s\n", scope_name);
	else
	{
		printf("Symbol table %s", "BLOCK ");
		printf("%d\n", block_num);
	}
	Entry* cur = head_entry;
	while (cur != NULL)
	{
		cur->printEntry();
		cur = cur->next_entry;
	}
	return;
}
/*
int main()
{
	//Testing Entry:
	//Entry e;
	//e.addID("flower", "STRING");
	//e.addValue("lily");
	//Entry a;
	//a.addID("age", "INT");
	//e.printEntry();
	//a.printEntry();
	//Testing SymTable:
	SymTable* global = new SymTable("GLOBAL");
	global->addEntry("a", "INT");
	global->addEntry("b", "INT");
	global->addEntry("c", "FLOAT");
	global->addEntry("d", "FLOAT");
	global->addEntry("fruit", "STRING", "mango");
	global->addEntry("num_fruits", "INT");
	global->printTable();
	SymTable* func_ripen = new SymTable("FUNC_RIPEN");
	func_ripen->addEntry("days_to_ripen", "INT");
	func_ripen->addEntry("percentage_ripe", "FLOAT");
	func_ripen->addEntry("ripe_color", "STRING", "orange");
	global->addChild(func_ripen);
	SymTable* block1 = new SymTable("BLOCK1");
	block1->addEntry("leaves", "INT");
	block1->addEntry("stem", "INT");
	func_ripen->addChild(block1);
	SymTable* block2 = new SymTable("BLOCK2");
	block2->addEntry("patches", "FLOAT");
	block2->addEntry("stems", "INT");
	func_ripen->addChild(block2);
	func_ripen->printTable();
	block1->printTable();
	block2->printTable();
	printf("\n\n");
	SymTable* func_burst = new SymTable("FUNC_BURST");
	func_burst->addEntry("days_to_burst", "INT");
	func_burst->addEntry("percentage_explosion", "FLOAT");
	func_burst->addEntry("burst_sound", "STRING", "boom");
	global->addChild(func_burst);
	func_burst->printTable();

	global->printChildList();
	func_ripen->printChildList();
	printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n");
	global->printAllInScope();
	//global->addChild(block3);
	return 0;
}	
*/
Entry::Entry(char* name_to_set, char* type_to_set, char* value_to_set /*= ""*/, bool is_arg_to_set /* = false */)
{
	name = name_to_set;
	type = type_to_set;
	value = value_to_set;
	is_arg = is_arg_to_set;
	next_entry = NULL;
}
void Entry::addID(char* name_to_add, char* type_to_add)
{
	name = name_to_add;
	type = type_to_add; 
	return;
}
void Entry::addValue(char* value_to_add)
{
	value = value_to_add;
	return;
}
void Entry::printEntry(bool printFunc /*= false*/)
{
	if (type == "STRING")
	{
		printf("name %s type %s value %s\n", name, type, value);
	}
	if (type == "INT" || type == "FLOAT")
	{
		printf("name %s type %s\n", name, type);
	}
	if (type == "FUNCTION")
	{
		printf("name %s type\n", name, type);
	}
	return;
}




/*
class StrEntry:Entry
{
	public:
		void addID(char* name_to_add);
		void addValue(char* value_to_add);

};
void StrEntry::addID(char* name_to_add)
{	

}
class StrEntry
{
	public:
		char *name, *value;
		void addID(char* name_to_add);
		void addValue(char* value_to_add);
		void printStrEntry();
};
class IntEntry
{
	public:
		char *name;
		void addID(char* name_to_add);
		void printIntEntry();
};
class FloatEntry
{
	public:
		char *name;
		void addID(char* name_to_add);
		void printFloatEntry();
};
class FuncEntry
{
	public:
		char *name;
		void addID(char* name_to_add);
		void printFuncEntry();
};
*/
