/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "parser.ypp" /* yacc.c:339  */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<string>
#include"ast_node.cpp"
//define YY_DECL extern "C" int yylex(void)
void yyerror(char* s);  //added by me
int yylex();            //added by me
bool declaration = false;
char* cur_var_type = "INVALID";
extern int linenum;
int block_cnt;
int accepted = 1;
bool verbose = false;
ASTNode* top_ast_node;

#line 84 "parser.tab.cpp" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parser.tab.hpp".  */
#ifndef YY_YY_PARSER_TAB_HPP_INCLUDED
# define YY_YY_PARSER_TAB_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    PROGRAM = 258,
    _BEGIN = 259,
    END = 260,
    FUNCTION = 261,
    READ = 262,
    WRITE = 263,
    IF = 264,
    ELSE = 265,
    FI = 266,
    FOR = 267,
    ROF = 268,
    RETURN = 269,
    INT = 270,
    VOID = 271,
    STRING = 272,
    FLOAT = 273,
    PLUS_OP = 274,
    MINUS_OP = 275,
    COLONEQUAL_OP = 276,
    STAR_OP = 277,
    DIVIDE_OP = 278,
    EQUAL_OP = 279,
    NOTEQUAL_OP = 280,
    LESSTHAN_OP = 281,
    GREATERTHAN_OP = 282,
    OPENPARAN_OP = 283,
    CLOSEPARAN_OP = 284,
    SEMICOLON_OP = 285,
    COMMA_OP = 286,
    LESSTHANEQUAL_OP = 287,
    GREATERTHANEQUAL_OP = 288,
    IDENTIFIER = 289,
    INTLITERAL = 290,
    FLOATLITERAL = 291,
    STRINGLITERAL = 292
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 19 "parser.ypp" /* yacc.c:355  */

	struct Entry* entry;
	struct ASTNode* ast_node;
	struct ASTNodeAddr* ast_node_addr;
	char* str_val;

#line 169 "parser.tab.cpp" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 186 "parser.tab.cpp" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   130

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  38
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  55
/* YYNRULES -- Number of rules.  */
#define YYNRULES  87
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  150

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   292

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    71,    71,    71,    76,    77,    77,    84,    85,    86,
      88,    89,    91,    91,    92,    93,    94,    94,    95,    95,
      98,    98,   101,   103,   103,   105,   108,   108,   113,   116,
     117,   117,   128,   128,   130,   133,   134,   134,   134,   135,
     135,   135,   135,   137,   138,   140,   142,   144,   146,   147,
     147,   148,   149,   149,   150,   150,   151,   152,   152,   152,
     152,   155,   155,   156,   156,   158,   158,   159,   159,   161,
     166,   161,   169,   169,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   181,   182,   182,   184,   184
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "PROGRAM", "_BEGIN", "END", "FUNCTION",
  "READ", "WRITE", "IF", "ELSE", "FI", "FOR", "ROF", "RETURN", "INT",
  "VOID", "STRING", "FLOAT", "PLUS_OP", "MINUS_OP", "COLONEQUAL_OP",
  "STAR_OP", "DIVIDE_OP", "EQUAL_OP", "NOTEQUAL_OP", "LESSTHAN_OP",
  "GREATERTHAN_OP", "OPENPARAN_OP", "CLOSEPARAN_OP", "SEMICOLON_OP",
  "COMMA_OP", "LESSTHANEQUAL_OP", "GREATERTHANEQUAL_OP", "IDENTIFIER",
  "INTLITERAL", "FLOATLITERAL", "STRINGLITERAL", "$accept", "program",
  "$@1", "id", "pgm_body", "$@2", "decl", "string_decl", "str", "var_decl",
  "$@3", "var_type", "any_type", "id_list", "$@4", "id_tail", "$@5",
  "param_decl_list", "param_decl", "param_decl_tail", "func_declarations",
  "func_decl", "$@6", "func_body", "$@7", "stmt_list", "stmt", "base_stmt",
  "assign_stmt", "assign_expr", "read_stmt", "write_stmt", "return_stmt",
  "expr", "expr_prefix", "factor", "factor_prefix", "postfix_expr",
  "call_expr", "primary", "expr_list", "expr_list_tail", "addop", "mulop",
  "if_stmt", "$@8", "$@9", "else_part", "$@10", "cond", "compop",
  "init_stmt", "incr_stmt", "for_stmt", "$@11", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292
};
# endif

#define YYPACT_NINF -84

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-84)))

#define YYTABLE_NINF -63

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
       2,   -11,    27,   -84,    48,   -84,   -84,    -2,   -84,   -11,
     -84,    16,   -84,    -2,    -2,   -84,    32,   -84,    49,   -84,
     -84,   -11,    19,    13,   -84,    49,   -84,    24,   -84,    28,
     -84,   -84,   -11,   -84,    26,   -84,   -84,   -84,   -11,   -84,
      33,   -84,    17,    26,   -11,    31,    34,   -84,   -84,    60,
      17,   -84,   -84,    34,    61,    -2,   -84,   -84,     0,    39,
      40,   -84,   -84,   -84,    50,   -84,     0,   -84,   -84,    42,
     -84,   -84,   -84,   -84,   -84,   -11,   -11,    41,    45,    44,
     -84,   -84,   -84,   -84,    51,    52,   -84,   -11,   -84,    21,
      15,   -84,    54,    55,    -7,    57,   -84,    58,   -84,   -84,
     -84,   -84,   -84,   -84,    59,    14,   -84,   -84,   -84,   -84,
     -84,   -84,   -84,   -84,   -84,   -84,   -84,    -2,   -84,    63,
      64,   -84,   -84,   -84,   -84,     0,    65,   -84,    47,    67,
     -84,   -11,   -84,   -84,   -84,    69,   -84,    68,    47,   -84,
      78,    -2,   -84,    -2,   -84,     0,     0,    77,   -84,   -84
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     4,     0,     1,     2,     9,    15,     0,
      14,     0,     5,     9,     9,    12,     0,     3,    29,     7,
       8,     0,     0,     0,     6,    29,    18,     0,    11,     0,
      17,    16,     0,    28,    22,    13,    10,    30,     0,    19,
       0,    20,    24,    22,     0,     0,    27,    21,    25,     0,
       0,    23,    32,    27,     0,     9,    26,    31,    35,     0,
       0,    69,    86,    50,     0,    33,    35,    36,    39,     0,
      40,    41,    42,    37,    38,     0,     0,     0,     0,     0,
      53,    50,    34,    43,     0,     0,    50,    83,    47,    48,
       0,    44,     0,     0,     0,     0,    82,     0,    65,    66,
      49,    50,    59,    60,    58,    51,    55,    54,    45,    46,
      78,    79,    76,    77,    80,    81,    50,     9,    50,     0,
      50,    67,    68,    52,    75,    35,     0,    57,    64,     0,
      70,    85,    50,    61,    56,    74,    84,     0,    64,    72,
       0,     9,    63,     9,    71,    35,    35,     0,    73,    87
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -84,   -84,   -84,     1,   -84,   -84,   -13,   -84,   -84,   -84,
     -84,   -12,   -84,   -29,   -84,    56,   -84,   -84,    20,    53,
      73,   -84,   -84,   -84,   -84,   -63,   -84,   -84,   -84,   -83,
     -84,   -84,   -84,   -57,   -84,   -84,   -84,   -84,   -84,   -84,
     -84,   -44,   -84,   -84,   -84,   -84,   -84,   -84,   -84,   -18,
     -84,   -84,   -84,   -84,   -84
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     7,    64,    11,    18,    12,    13,    29,    14,
      21,    15,    32,    27,    34,    39,    43,    45,    46,    51,
      24,    25,    40,    54,    55,    65,    66,    67,    68,    69,
      70,    71,    72,    94,    80,    89,    90,   105,   106,   107,
     129,   133,   100,   123,    73,    77,   135,   140,   143,    95,
     116,    97,   137,    74,    78
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      19,    20,     4,    82,    96,     1,    79,    59,    60,    61,
      16,    31,    62,     8,    63,     9,    10,   110,   111,   112,
     113,    17,    26,     3,    91,   114,   115,     5,     8,    30,
      44,    10,     8,    37,     3,    10,   121,   122,    44,    41,
      98,    99,    58,   101,   119,    48,    84,    85,   136,     3,
     102,   103,     6,    22,    35,    23,    28,    38,    36,   124,
      49,    42,   130,   128,    52,    50,    57,    75,    76,    86,
      53,    81,    83,    87,    88,   138,    26,    26,   132,   139,
      92,    93,   147,   148,   108,   109,   117,   120,   118,   144,
     149,   104,   127,   -62,   142,   131,   134,   141,    33,    47,
     126,     0,     0,     0,   125,     0,    56,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   145,     0,
     146
};

static const yytype_int16 yycheck[] =
{
      13,    14,     1,    66,    87,     3,    63,     7,     8,     9,
       9,    23,    12,    15,    14,    17,    18,    24,    25,    26,
      27,     5,    21,    34,    81,    32,    33,     0,    15,    16,
      42,    18,    15,    32,    34,    18,    22,    23,    50,    38,
      19,    20,    55,    28,   101,    44,    75,    76,   131,    34,
      35,    36,     4,    21,    30,     6,    37,    31,    30,   116,
      29,    28,   125,   120,     4,    31,     5,    28,    28,    28,
      50,    21,    30,    28,    30,   132,    75,    76,    31,    10,
      29,    29,   145,   146,    30,    30,    29,    28,    30,    11,
      13,    90,    29,    29,   138,    30,    29,    29,    25,    43,
     118,    -1,    -1,    -1,   117,    -1,    53,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   141,    -1,
     143
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    39,    34,    41,     0,     4,    40,    15,    17,
      18,    42,    44,    45,    47,    49,    41,     5,    43,    44,
      44,    48,    21,     6,    58,    59,    41,    51,    37,    46,
      16,    49,    50,    58,    52,    30,    30,    41,    31,    53,
      60,    41,    28,    54,    49,    55,    56,    53,    41,    29,
      31,    57,     4,    56,    61,    62,    57,     5,    44,     7,
       8,     9,    12,    14,    41,    63,    64,    65,    66,    67,
      68,    69,    70,    82,    91,    28,    28,    83,    92,    71,
      72,    21,    63,    30,    51,    51,    28,    28,    30,    73,
      74,    71,    29,    29,    71,    87,    67,    89,    19,    20,
      80,    28,    35,    36,    41,    75,    76,    77,    30,    30,
      24,    25,    26,    27,    32,    33,    88,    29,    30,    71,
      28,    22,    23,    81,    71,    44,    87,    29,    71,    78,
      63,    30,    31,    79,    29,    84,    67,    90,    71,    10,
      85,    29,    79,    86,    11,    44,    44,    63,    63,    13
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    38,    40,    39,    41,    43,    42,    44,    44,    44,
      45,    46,    48,    47,    49,    49,    50,    50,    52,    51,
      54,    53,    53,    55,    55,    56,    57,    57,    58,    58,
      60,    59,    62,    61,    63,    63,    64,    64,    64,    65,
      65,    65,    65,    66,    67,    68,    69,    70,    71,    72,
      72,    73,    74,    74,    75,    75,    76,    77,    77,    77,
      77,    78,    78,    79,    79,    80,    80,    81,    81,    83,
      84,    82,    86,    85,    85,    87,    88,    88,    88,    88,
      88,    88,    89,    89,    90,    90,    92,    91
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     6,     1,     0,     3,     2,     2,     0,
       5,     1,     0,     4,     1,     1,     1,     1,     0,     3,
       0,     4,     0,     2,     0,     2,     3,     0,     2,     0,
       0,    10,     0,     3,     2,     0,     1,     1,     1,     1,
       1,     1,     1,     2,     3,     5,     5,     3,     2,     3,
       0,     2,     3,     0,     1,     1,     4,     3,     1,     1,
       1,     2,     0,     3,     0,     1,     1,     1,     1,     0,
       0,    10,     0,     4,     0,     3,     1,     1,     1,     1,
       1,     1,     1,     0,     1,     0,     0,    12
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 71 "parser.ypp" /* yacc.c:1646  */
    {
					/*SymTable* */global_table = new SymTable("GLOBAL"); 
					head_scope = new ScopeNode(global_table);
					cur_scope = head_scope;}
#line 1377 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 76 "parser.ypp" /* yacc.c:1646  */
    {(yyval.str_val) = (yyvsp[0].str_val);}
#line 1383 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 77 "parser.ypp" /* yacc.c:1646  */
    {initialize();}
#line 1389 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 78 "parser.ypp" /* yacc.c:1646  */
    { (yyval.ast_node) = new ASTNode("n/a", "PGM_BODY"); 
					(yyval.ast_node)->addChild((yyvsp[-2].ast_node)); 
					if ((yyvsp[0].ast_node) == NULL) {(yyval.ast_node) = new ASTNode("n/a", "func_declarations is empty");}
					else{(yyval.ast_node)->addChild((yyvsp[0].ast_node));} 
					top_ast_node = (yyval.ast_node); 
					(yyval.ast_node)->generate_code();}
#line 1400 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 84 "parser.ypp" /* yacc.c:1646  */
    { if ((yyvsp[0].ast_node) == NULL) {(yyval.ast_node) = new ASTNode("n/a", "DECL"); (yyval.ast_node)->children = new ASTNodeAddr((yyvsp[-1].ast_node_addr));} else {(yyval.ast_node) = (yyvsp[0].ast_node); ASTNodeAddr* tmp = (yyval.ast_node)->children; (yyval.ast_node)->children = new ASTNodeAddr((yyvsp[-1].ast_node_addr)); (yyval.ast_node)->children->next = tmp;}}
#line 1406 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 85 "parser.ypp" /* yacc.c:1646  */
    { if ((yyvsp[0].ast_node) == NULL) {(yyval.ast_node) = new ASTNode("n/a", "DECL"); (yyval.ast_node)->children = new ASTNodeAddr((yyvsp[-1].ast_node_addr));} else {(yyval.ast_node) = (yyvsp[0].ast_node); ASTNodeAddr* tmp = (yyval.ast_node)->children; (yyval.ast_node)->children = new ASTNodeAddr((yyvsp[-1].ast_node_addr)); (yyval.ast_node)->children->next = tmp;}}
#line 1412 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 86 "parser.ypp" /* yacc.c:1646  */
    {(yyval.ast_node) = NULL;}
#line 1418 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 88 "parser.ypp" /* yacc.c:1646  */
    {(yyval.ast_node_addr) = new ASTNodeAddr(cur_scope->val->addEntry((yyvsp[-3].str_val), "STRING", (yyvsp[-1].str_val)));}
#line 1424 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 89 "parser.ypp" /* yacc.c:1646  */
    {(yyval.str_val) = (yyvsp[0].str_val);}
#line 1430 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 91 "parser.ypp" /* yacc.c:1646  */
    {declaration = true;}
#line 1436 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 91 "parser.ypp" /* yacc.c:1646  */
    {declaration = false; (yyval.ast_node_addr) = (yyvsp[-1].ast_node_addr);}
#line 1442 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 92 "parser.ypp" /* yacc.c:1646  */
    {(yyval.str_val) = "FLOAT"; cur_var_type = "FLOAT";}
#line 1448 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 93 "parser.ypp" /* yacc.c:1646  */
    {(yyval.str_val) = "INT";   cur_var_type = "INT";}
#line 1454 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 94 "parser.ypp" /* yacc.c:1646  */
    {(yyval.str_val) = (yyvsp[0].str_val);}
#line 1460 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 94 "parser.ypp" /* yacc.c:1646  */
    {(yyval.str_val) = "VOID";}
#line 1466 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 95 "parser.ypp" /* yacc.c:1646  */
    {if (declaration == true) cur_scope->val->addEntry((yyvsp[0].str_val), cur_var_type);}
#line 1472 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 96 "parser.ypp" /* yacc.c:1646  */
    {ASTNode* new_node = new ASTNode((yyvsp[-2].str_val), head_scope->val->findType((yyvsp[-2].str_val))); (yyval.ast_node_addr) = new ASTNodeAddr(new_node);
					(yyval.ast_node_addr)->next = (yyvsp[0].ast_node_addr);}
#line 1479 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 98 "parser.ypp" /* yacc.c:1646  */
    {if (declaration == true) cur_scope->val->addEntry((yyvsp[0].str_val), cur_var_type);}
#line 1485 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 99 "parser.ypp" /* yacc.c:1646  */
    {ASTNode* new_node = new ASTNode((yyvsp[-2].str_val), head_scope->val->findType((yyvsp[-2].str_val))); (yyval.ast_node_addr) = new ASTNodeAddr(new_node); 
				     (yyval.ast_node_addr)->next = (yyvsp[0].ast_node_addr);}
#line 1492 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 101 "parser.ypp" /* yacc.c:1646  */
    {(yyval.ast_node_addr) = NULL;}
#line 1498 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 103 "parser.ypp" /* yacc.c:1646  */
    {(yyval.ast_node_addr) = new ASTNodeAddr((yyvsp[-1].ast_node)); (yyval.ast_node_addr)->next = (yyvsp[0].ast_node_addr);}
#line 1504 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 103 "parser.ypp" /* yacc.c:1646  */
    { (yyval.ast_node_addr) = NULL;}
#line 1510 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 106 "parser.ypp" /* yacc.c:1646  */
    {cur_scope->val->addEntry((yyvsp[0].str_val), (yyvsp[-1].str_val), "", true); /*specifying that it is an arg*/
                    (yyval.ast_node) = new ASTNode((yyvsp[-1].str_val), (yyvsp[0].str_val)); }
#line 1517 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 108 "parser.ypp" /* yacc.c:1646  */
    {(yyval.ast_node_addr) = new ASTNodeAddr((yyvsp[-1].ast_node)); (yyval.ast_node_addr)->next = (yyvsp[0].ast_node_addr);}
#line 1523 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 108 "parser.ypp" /* yacc.c:1646  */
    {(yyval.ast_node_addr) = NULL;}
#line 1529 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 113 "parser.ypp" /* yacc.c:1646  */
    { 
					if ((yyvsp[0].ast_node) == NULL) {(yyval.ast_node) = new ASTNode("n/a", "FUNC_DECLARATIONS"); (yyval.ast_node)->addChild((yyvsp[-1].ast_node));}
					else {(yyval.ast_node) = (yyvsp[0].ast_node); ASTNodeAddr* tmp = (yyval.ast_node)->children; (yyval.ast_node)->children = new ASTNodeAddr((yyvsp[-1].ast_node)); (yyval.ast_node)->children->next = tmp;}}
#line 1537 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 116 "parser.ypp" /* yacc.c:1646  */
    {(yyval.ast_node) = NULL;}
#line 1543 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 117 "parser.ypp" /* yacc.c:1646  */
    {
					SymTable* new_table = new SymTable((yyvsp[0].str_val), 0, (yyvsp[-1].str_val));cur_scope->next_scope = new ScopeNode(new_table, cur_scope); cur_scope=cur_scope->next_scope;
					head_scope->val->addChild(cur_scope->val); }
#line 1551 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 121 "parser.ypp" /* yacc.c:1646  */
    {
					cur_scope = cur_scope->prev_scope; delete cur_scope->next_scope;
					(yyval.ast_node) = new ASTNode("n/a", "FUNC_DECL"); (yyval.ast_node)->addChild(new ASTNode((yyvsp[-8].str_val), "ret type of func"));/*type*/ 
					(yyval.ast_node)->addChild((ASTNode*)((yyvsp[-7].str_val))); /*id*/ 
					ASTNode* params = new ASTNode("n/a", "PARAM_DECL_LIST"); params -> children = (yyvsp[-4].ast_node_addr); (yyval.ast_node)->addChild(params); /*param_decl_list*/ 
					(yyval.ast_node)->addChild((yyvsp[-1].ast_node)); /*func_body*/ }
#line 1562 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 128 "parser.ypp" /* yacc.c:1646  */
    { }
#line 1568 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 128 "parser.ypp" /* yacc.c:1646  */
    {  (yyval.ast_node) = new ASTNode("n/a", "FUNC_BODY"); (yyval.ast_node)->addChild((yyvsp[-1].ast_node)); (yyval.ast_node)->addChild((yyvsp[0].ast_node));}
#line 1574 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 131 "parser.ypp" /* yacc.c:1646  */
    { if ((yyvsp[0].ast_node) == NULL) {(yyval.ast_node) = new ASTNode("n/a", "STMT_LIST"); (yyval.ast_node)->children = new ASTNodeAddr((yyvsp[-1].ast_node));}
					else {ASTNodeAddr* tmp = (yyvsp[0].ast_node)->children; (yyvsp[0].ast_node)->children = new ASTNodeAddr((yyvsp[-1].ast_node)); (yyvsp[0].ast_node)->children->next = tmp; (yyval.ast_node) = (yyvsp[0].ast_node);}}
#line 1581 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 133 "parser.ypp" /* yacc.c:1646  */
    {(yyval.ast_node) = NULL;}
#line 1587 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 134 "parser.ypp" /* yacc.c:1646  */
    {(yyval.ast_node) = (yyvsp[0].ast_node); /*gen3AC_stmt($$);*/}
#line 1593 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 134 "parser.ypp" /* yacc.c:1646  */
    {(yyval.ast_node) = (yyvsp[0].ast_node); /*gen3AC_stmt($$);*/}
#line 1599 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 134 "parser.ypp" /* yacc.c:1646  */
    {(yyval.ast_node) = (yyvsp[0].ast_node);}
#line 1605 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 135 "parser.ypp" /* yacc.c:1646  */
    {(yyval.ast_node) = (yyvsp[0].ast_node);}
#line 1611 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 135 "parser.ypp" /* yacc.c:1646  */
    {(yyval.ast_node) = (yyvsp[0].ast_node);}
#line 1617 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 135 "parser.ypp" /* yacc.c:1646  */
    {(yyval.ast_node) = (yyvsp[0].ast_node);}
#line 1623 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 135 "parser.ypp" /* yacc.c:1646  */
    {(yyval.ast_node) = (yyvsp[0].ast_node);}
#line 1629 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 137 "parser.ypp" /* yacc.c:1646  */
    {(yyval.ast_node) = (yyvsp[-1].ast_node);}
#line 1635 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 138 "parser.ypp" /* yacc.c:1646  */
    {
					(yyval.ast_node) = new ASTNode(":=", "STORE"); (yyval.ast_node)->addChild(new ASTNode((yyvsp[-2].str_val), head_scope->val->findType((yyvsp[-2].str_val)))); (yyval.ast_node)->addChild((yyvsp[0].ast_node)); assign_list->addChild((yyval.ast_node)); }
#line 1642 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 140 "parser.ypp" /* yacc.c:1646  */
    {
					(yyval.ast_node) = new ASTNode((char*)(yyvsp[-2].ast_node_addr), "READ"); assign_list->addChild((yyval.ast_node));}
#line 1649 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 142 "parser.ypp" /* yacc.c:1646  */
    {
					(yyval.ast_node) = new ASTNode((char*)(yyvsp[-2].ast_node_addr), "WRITE"); assign_list->addChild((yyval.ast_node));}
#line 1656 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 144 "parser.ypp" /* yacc.c:1646  */
    { (yyval.ast_node) = new ASTNode("see child for value", "RET_STMT"); (yyval.ast_node)->addChild((yyvsp[-1].ast_node));}
#line 1662 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 146 "parser.ypp" /* yacc.c:1646  */
    {if ((yyvsp[-1].ast_node) == NULL) {(yyval.ast_node) = (yyvsp[0].ast_node);} else {(yyvsp[-1].ast_node)->addChild((yyvsp[0].ast_node)); (yyval.ast_node) = (yyvsp[-1].ast_node);}}
#line 1668 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 147 "parser.ypp" /* yacc.c:1646  */
    {if ((yyvsp[-2].ast_node) == NULL) {(yyvsp[0].ast_node)->addChild((yyvsp[-1].ast_node)); (yyval.ast_node) = (yyvsp[0].ast_node);} else {(yyvsp[-2].ast_node)->addChild((yyvsp[-1].ast_node)); (yyvsp[0].ast_node)->addChild((yyvsp[-2].ast_node)); (yyval.ast_node) = (yyvsp[0].ast_node); }}
#line 1674 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 147 "parser.ypp" /* yacc.c:1646  */
    {(yyval.ast_node) = NULL;}
#line 1680 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 148 "parser.ypp" /* yacc.c:1646  */
    {if ((yyvsp[-1].ast_node) == NULL) {(yyval.ast_node) = (yyvsp[0].ast_node);} else {(yyvsp[-1].ast_node)->addChild((yyvsp[0].ast_node)); (yyval.ast_node) = (yyvsp[-1].ast_node); if(verbose) printf("factor: %s, factor_prefix = %s, postfix_expr = %s  ", (yyval.ast_node)->value, (yyvsp[-1].ast_node)->value, (yyvsp[0].ast_node)->value); }}
#line 1686 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 149 "parser.ypp" /* yacc.c:1646  */
    {if ((yyvsp[-2].ast_node) == NULL) {(yyvsp[0].ast_node)->addChild((yyvsp[-1].ast_node)); (yyval.ast_node) = (yyvsp[0].ast_node);} else {(yyvsp[-2].ast_node)->addChild((yyvsp[-1].ast_node)); (yyvsp[0].ast_node)->addChild((yyvsp[-2].ast_node)); (yyval.ast_node) = (yyvsp[0].ast_node);}}
#line 1692 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 149 "parser.ypp" /* yacc.c:1646  */
    {(yyval.ast_node) = NULL;}
#line 1698 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 150 "parser.ypp" /* yacc.c:1646  */
    {(yyval.ast_node) = (yyvsp[0].ast_node);}
#line 1704 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 150 "parser.ypp" /* yacc.c:1646  */
    {(yyval.ast_node) = (yyvsp[0].ast_node);}
#line 1710 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 151 "parser.ypp" /* yacc.c:1646  */
    {(yyval.ast_node) = new ASTNode((yyvsp[-3].str_val), "FUNC_CALL"); (yyval.ast_node)->children = (yyvsp[-1].ast_node_addr);}
#line 1716 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 152 "parser.ypp" /* yacc.c:1646  */
    {(yyval.ast_node) = (yyvsp[-1].ast_node);}
#line 1722 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 152 "parser.ypp" /* yacc.c:1646  */
    {(yyval.ast_node) = new ASTNode((yyvsp[0].str_val), head_scope->val->findType((yyvsp[0].str_val)));}
#line 1728 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 152 "parser.ypp" /* yacc.c:1646  */
    {(yyval.ast_node) = new ASTNode((yyvsp[0].str_val), "INTLITERAL");  }
#line 1734 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 152 "parser.ypp" /* yacc.c:1646  */
    {(yyval.ast_node) = new ASTNode((yyvsp[0].str_val), "FLOATLITERAL");}
#line 1740 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 155 "parser.ypp" /* yacc.c:1646  */
    {(yyval.ast_node_addr) = new ASTNodeAddr((yyvsp[-1].ast_node)); (yyval.ast_node_addr)->next = (yyvsp[0].ast_node_addr);}
#line 1746 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 155 "parser.ypp" /* yacc.c:1646  */
    {(yyval.ast_node_addr) = NULL;}
#line 1752 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 156 "parser.ypp" /* yacc.c:1646  */
    {(yyval.ast_node_addr) = new ASTNodeAddr((yyvsp[-1].ast_node)); (yyval.ast_node_addr)->next = (yyvsp[0].ast_node_addr);}
#line 1758 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 156 "parser.ypp" /* yacc.c:1646  */
    {(yyval.ast_node_addr) = NULL;}
#line 1764 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 158 "parser.ypp" /* yacc.c:1646  */
    {(yyval.ast_node) = new ASTNode("+", "ADD");}
#line 1770 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 158 "parser.ypp" /* yacc.c:1646  */
    {(yyval.ast_node) = new ASTNode("-", "SUB");}
#line 1776 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 159 "parser.ypp" /* yacc.c:1646  */
    {(yyval.ast_node) = new ASTNode("*", "MUL");}
#line 1782 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 159 "parser.ypp" /* yacc.c:1646  */
    {(yyval.ast_node) = new ASTNode("/", "DIV");}
#line 1788 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 161 "parser.ypp" /* yacc.c:1646  */
    {block_cnt++; char* block_name = "BLOCK"; SymTable* new_table = new SymTable(block_name, block_cnt);
                        cur_scope->next_scope = new ScopeNode(new_table, cur_scope); cur_scope=cur_scope->next_scope;
                        head_scope->val->addChild(cur_scope->val);}
#line 1796 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 166 "parser.ypp" /* yacc.c:1646  */
    {cur_scope = cur_scope->prev_scope; delete cur_scope->next_scope;}
#line 1802 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 168 "parser.ypp" /* yacc.c:1646  */
    {(yyval.ast_node) = new ASTNode("n/a", "IF"); (yyval.ast_node)->addChild((yyvsp[-6].ast_node)); if ((yyvsp[-4].ast_node) != NULL)(yyval.ast_node)->addChild((yyvsp[-4].ast_node)); else (yyval.ast_node)->addChild(new ASTNode("n/a", "decl is empty")); (yyval.ast_node)->addChild((yyvsp[-3].ast_node)); if ((yyvsp[-1].ast_node) != NULL) (yyval.ast_node)->addChild((yyvsp[-1].ast_node)); else (yyval.ast_node)->addChild(new ASTNode("n/a", "else_part is NULL"));}
#line 1808 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 169 "parser.ypp" /* yacc.c:1646  */
    {block_cnt++; char* block_name = "BLOCK"; SymTable* new_table = new SymTable(block_name, block_cnt);
                        cur_scope->next_scope = new ScopeNode(new_table, cur_scope); cur_scope=cur_scope->next_scope;
                        head_scope->val->addChild(cur_scope->val);}
#line 1816 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 172 "parser.ypp" /* yacc.c:1646  */
    {cur_scope = cur_scope->prev_scope; delete cur_scope->next_scope;
					(yyval.ast_node) = new ASTNode("n/a", "ELSE_PART"); if((yyvsp[-1].ast_node) != NULL) (yyval.ast_node)->addChild((yyvsp[-1].ast_node)); else (yyval.ast_node)->addChild(new ASTNode("n/a", "decl is empty")); (yyval.ast_node)->addChild((yyvsp[0].ast_node)); }
#line 1823 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 173 "parser.ypp" /* yacc.c:1646  */
    {(yyval.ast_node) = NULL;}
#line 1829 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 174 "parser.ypp" /* yacc.c:1646  */
    {(yyval.ast_node) = (yyvsp[-1].ast_node); (yyval.ast_node)->addChild((yyvsp[-2].ast_node)); (yyval.ast_node)->addChild((yyvsp[0].ast_node)); }
#line 1835 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 175 "parser.ypp" /* yacc.c:1646  */
    {(yyval.ast_node) = new ASTNode("<", "LT");}
#line 1841 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 176 "parser.ypp" /* yacc.c:1646  */
    {(yyval.ast_node) = new ASTNode(">", "GT");}
#line 1847 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 177 "parser.ypp" /* yacc.c:1646  */
    {(yyval.ast_node) = new ASTNode("=", "EQ");}
#line 1853 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 178 "parser.ypp" /* yacc.c:1646  */
    {(yyval.ast_node) = new ASTNode("!=", "NE");}
#line 1859 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 179 "parser.ypp" /* yacc.c:1646  */
    {(yyval.ast_node) = new ASTNode("<=", "LE");}
#line 1865 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 180 "parser.ypp" /* yacc.c:1646  */
    {(yyval.ast_node) = new ASTNode(">=", "GE");}
#line 1871 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 181 "parser.ypp" /* yacc.c:1646  */
    {(yyval.ast_node) = (yyvsp[0].ast_node);}
#line 1877 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 181 "parser.ypp" /* yacc.c:1646  */
    {(yyval.ast_node) = NULL;}
#line 1883 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 182 "parser.ypp" /* yacc.c:1646  */
    {(yyval.ast_node) = (yyvsp[0].ast_node);}
#line 1889 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 182 "parser.ypp" /* yacc.c:1646  */
    {(yyval.ast_node) = NULL;}
#line 1895 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 184 "parser.ypp" /* yacc.c:1646  */
    {block_cnt++; char* block_name = "BLOCK"; SymTable* new_table = new SymTable(block_name, block_cnt);
						cur_scope->next_scope = new ScopeNode(new_table, cur_scope); cur_scope=cur_scope->next_scope; 
						head_scope->val->addChild(cur_scope->val);}
#line 1903 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 188 "parser.ypp" /* yacc.c:1646  */
    {cur_scope = cur_scope->prev_scope; delete cur_scope->next_scope; 
					(yyval.ast_node) = new ASTNode("n/a", "FOR_STMT"); 
					if ((yyvsp[-8].ast_node) == NULL) {(yyval.ast_node)->addChild(new ASTNode("", "init_stmt is empty"));} else {(yyval.ast_node)->addChild((yyvsp[-8].ast_node)); }/*init_stmt*/ 
					(yyval.ast_node)->addChild((yyvsp[-6].ast_node)); /*cond*/ 
					if ((yyvsp[-4].ast_node) == NULL) {(yyval.ast_node)->addChild(new ASTNode("", "incr_stmt is empty"));} else {(yyval.ast_node)->addChild((yyvsp[-4].ast_node)); }/*incr_stmt*/ 
					(yyval.ast_node)->addChild((yyvsp[-2].ast_node)); /*decl*/ 
					(yyval.ast_node)->addChild((yyvsp[-1].ast_node)); /*stmt_list*/}
#line 1915 "parser.tab.cpp" /* yacc.c:1646  */
    break;


#line 1919 "parser.tab.cpp" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 195 "parser.ypp" /* yacc.c:1906  */


void yyerror(char* s)
{
        //printf("Not accepted, line_num = %d\n", linenum);
        //printf("Not accepted");
		accepted = 0;
}
int main()
{
        yyparse();
		/*if (accepted == 1)
			printf("Accepted");*/
		//head_scope->val->printAllInScope(); //printing symbol table
		assign_list->printEntry(); //printing ASTs
		//top_ast_node->printEntry(); //printing ASTs
		//gen3AC(assign_list);
		//printLinkedList(head_code); //printing 3AC
		gen_asm(head_code);
		printLinkedList(head_asm);  //printing assembly
}
