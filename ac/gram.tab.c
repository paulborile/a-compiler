
/*  A Bison parser, made from gram.y  */

#define YARRAY  258
#define YBEGIN  259
#define YCALL   260
#define YDO 261
#define YELSE   262
#define YEND    263
#define YEXPORT 264
#define YIF 265
#define YIMPORT 266
#define YMODULE 267
#define YNULL   268
#define YPROG   269
#define YPROC   270
#define YREAD   271
#define YR_STR  272
#define YTHEN   273
#define YVAR    274
#define YWHILE  275
#define YWRITE  276
#define YW_STR  277
#define YASSIGN 278
#define YEQ 279
#define YSEMICOL    280
#define YCOMMA  281
#define YMINUS  282
#define YPLUS   283
#define YMULT   284
#define YDIV    285
#define YLBRA   286
#define YRBRA   287
#define YDOT    288
#define YLES_EQ 289
#define YGRE_EQ 290
#define YLESS   291
#define YGREAT  292
#define YNOTEQ  293
#define YSLBRA  294
#define YSRBRA  295
#define YNUMBER 296
#define YSTRING 297
#define VNAME   298

#line 37 "gram.y"

#include    <stdio.h>
#include    "extern.h"
#include    "structs.h"
#include    "instcod.h"

/* working variables for dtab */

extern int d_size;
extern int d_cnt;
extern int d_first;
extern struct  dtab *dbase;
extern struct  dtab *done;
extern struct  dtab *dtwo;
struct  dtab *d_dummy;
struct  dtab *d_init(), *d_add(), *d_search();

/* working variables for etab */

extern int e_size;
extern int e_cnt;
extern int e_first;
extern struct  etab *ebase;
extern struct  etab *eone;
extern struct  etab *etwo;
struct  etab *e_dummy;
struct  etab *e_init(), *e_add(), *e_search();
struct  etab *e_read, *e_write, *e_rd_str, *e_wr_str;

/* working variables for rtab */

extern int r_size;
extern int r_first;
extern struct  rtab *rbase;
extern struct  rtab *rone;
extern struct  rtab *rtwo;
struct  rtab *r_init(), *r_add();

/* working variables for itab */

extern int i_size;
extern int i_cnt;

/* define externs for lvtab */

extern int lv_size;
extern int lv_cnt;
extern int lv_first;
extern struct  lvtab *lvbase;
extern struct  lvtab *lvone;
extern struct  lvtab *lvtwo;
extern struct  lvtab *lv_init(), *lv_add(), *lv_search();

/* for -S option only */

extern char *as_make_label();


int l_cnt = 100;

struct  lvtab *lv_dummy;

char tsave[MAXVAR];
char pname[MAXVAR];
char p_param[MAXVAR];
char procname[MAXVAR];
extern char yytext[];
int a, b;
int in_proc, act_sp;
int is_param, ar_len;
int io_in = 0;
int n_tabs = 0;

#ifndef YYLTYPE
typedef
    struct yyltype
{
    int timestamp;
    int first_line;
    int first_column; \ n      int last_line;
    int last_column;
    char *text;
}
yyltype;

#define YYLTYPE yyltype
#endif

#ifndef YYSTYPE
#define YYSTYPE int
#endif
#include <stdio.h>

#ifndef __STDC__
#define const
#endif



#define YYFINAL     249
#define YYFLAG      -32768
#define YYNTBASE    44

#define YYTRANSLATE(x) ((unsigned)(x) <= 298 ? yytranslate[x] : 118)

static const char yytranslate[] = {     0,
                                        2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
                                        2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
                                        2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
                                        2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
                                        2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
                                        2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
                                        2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
                                        2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
                                        2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
                                        2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
                                        2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
                                        2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
                                        2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
                                        2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
                                        2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
                                        2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
                                        2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
                                        2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
                                        2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
                                        2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
                                        2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
                                        2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
                                        2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
                                        2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
                                        2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
                                        2, 2, 2, 2, 2, 1, 2, 3, 4, 5,
                                        6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
                                        16, 17, 18, 19, 20, 21, 22, 23, 24, 25,
                                        26, 27, 28, 29, 30, 31, 32, 33, 34, 35,
                                        36, 37, 38, 39, 40, 41, 42, 43};

static const short yyprhs[] = {     0,
                                    0, 6, 7, 14, 17, 18, 22, 26, 27, 31,
                                    35, 36, 41, 46, 47, 53, 54, 60, 67, 69,
                                    71, 75, 77, 79, 83, 85, 87, 91, 93, 94,
                                    95, 102, 103, 104, 113, 115, 116, 117, 125, 127,
                                    128, 133, 138, 140, 144, 146, 147, 148, 155, 156,
                                    157, 166, 168, 169, 174, 176, 177, 182, 184, 186,
                                    189, 192, 195, 196, 197, 206, 207, 208, 216, 217,
                                    218, 226, 227, 228, 236, 237, 244, 245, 246, 247,
                                    248, 249, 261, 262, 263, 264, 272, 273, 274, 281,
                                    284, 286, 288, 289, 294, 295, 300, 301, 306, 307,
                                    312, 313, 318, 319, 324, 325, 330, 332, 333, 338,
                                    339, 344, 345, 350, 351, 356, 357, 362, 363, 368,
                                    370, 372, 374, 375, 381, 383, 384, 385};

static const short yyrhs[] = {    14,
                                  46, 50, 73, 33, 0, 0, 12, 48, 50, 45,
                                  13, 33, 0, 1, 25, 0, 0, 43, 47, 25,
                                  0, 1, 43, 25, 0, 0, 43, 49, 25, 0,
                                  1, 43, 25, 0, 0, 11, 53, 25, 50, 0,
                                  9, 54, 25, 50, 0, 0, 19, 55, 25, 51,
                                  50, 0, 0, 3, 56, 25, 52, 50, 0, 15,
                                  61, 64, 71, 25, 50, 0, 1, 0, 43, 0,
                                  53, 26, 43, 0, 1, 0, 43, 0, 54, 26,
                                  43, 0, 1, 0, 43, 0, 55, 26, 43, 0,
                                  1, 0, 0, 0, 43, 57, 39, 41, 58, 40,
                                  0, 0, 0, 56, 26, 43, 59, 39, 41, 60,
                                  40, 0, 1, 0, 0, 0, 43, 62, 31, 43,
                                  63, 32, 25, 0, 1, 0, 0, 19, 65, 25,
                                  64, 0, 3, 66, 25, 64, 0, 43, 0, 65,
                                  26, 43, 0, 1, 0, 0, 0, 43, 67, 39,
                                  41, 68, 40, 0, 0, 0, 66, 26, 43, 69,
                                  39, 41, 70, 40, 0, 1, 0, 0, 4, 72,
                                  75, 8, 0, 1, 0, 0, 4, 74, 75, 8,
                                  0, 1, 0, 76, 0, 76, 75, 0, 13, 25,
                                  0, 105, 25, 0, 0, 0, 5, 43, 77, 31,
                                  115, 78, 32, 25, 0, 0, 0, 16, 79, 31,
                                  115, 80, 32, 25, 0, 0, 0, 17, 81, 31,
                                  43, 82, 32, 25, 0, 0, 0, 21, 83, 31,
                                  115, 84, 32, 25, 0, 0, 22, 85, 31, 96,
                                  32, 25, 0, 0, 0, 0, 0, 0, 10, 86,
                                  97, 87, 18, 88, 76, 89, 7, 90, 76, 0,
                                  0, 0, 0, 20, 91, 97, 92, 6, 93, 76,
                                  0, 0, 0, 4, 94, 75, 8, 95, 25, 0,
                                  1, 25, 0, 42, 0, 43, 0, 0, 31, 98,
                                  97, 32, 0, 0, 107, 24, 99, 107, 0, 0,
                                  107, 38, 100, 107, 0, 0, 107, 36, 101, 107,
                                  0, 0, 107, 37, 102, 107, 0, 0, 107, 34,
                                  103, 107, 0, 0, 107, 35, 104, 107, 0, 1,
                                  0, 0, 115, 23, 106, 107, 0, 0, 31, 108,
                                  107, 32, 0, 0, 107, 28, 109, 107, 0, 0,
                                  107, 27, 110, 107, 0, 0, 107, 29, 111, 107,
                                  0, 0, 107, 30, 112, 107, 0, 41, 0, 113,
                                  0, 43, 0, 0, 43, 114, 39, 107, 40, 0,
                                  43, 0, 0, 0, 43, 116, 39, 117, 107, 40,
                                  0};

#if YYDEBUG != 0
static const short yyrline[] = { 0,
                                 115, 130, 135, 147, 154, 182, 182, 188, 206, 206,
                                 212, 213, 215, 217, 226, 226, 235, 235, 237, 249,
                                 257, 267, 279, 287, 297, 309, 322, 336, 347, 358,
                                 372, 372, 382, 395, 395, 401, 415, 422, 424, 431,
                                 432, 434, 438, 450, 462, 468, 472, 485, 485, 490,
                                 503, 503, 510, 514, 535, 546, 568, 584, 591, 592,
                                 595, 602, 609, 621, 630, 637, 649, 657, 663, 671,
                                 690, 691, 704, 712, 718, 735, 742, 751, 755, 761,
                                 774, 788, 801, 819, 825, 831, 849, 858, 866, 866,
                                 873, 886, 903, 911, 917, 926, 941, 950, 965, 974,
                                 989, 998, 1013, 1022, 1037, 1046, 1061, 1068, 1076, 1088,
                                 1094, 1100, 1108, 1118, 1126, 1136, 1144, 1154, 1162, 1172,
                                 1187, 1191, 1205, 1221, 1239, 1252, 1267, 1273};

static const char *const yytname[] = {   "$",
                                         "error", "$illegal.", "YARRAY", "YBEGIN", "YCALL", "YDO", "YELSE", "YEND", "YEXPORT", "YIF",
                                         "YIMPORT", "YMODULE", "YNULL", "YPROG", "YPROC", "YREAD", "YR_STR", "YTHEN", "YVAR", "YWHILE",
                                         "YWRITE", "YW_STR", "YASSIGN", "YEQ", "YSEMICOL", "YCOMMA", "YMINUS", "YPLUS", "YMULT", "YDIV",
                                         "YLBRA", "YRBRA", "YDOT", "YLES_EQ", "YGRE_EQ", "YLESS", "YGREAT", "YNOTEQ", "YSLBRA", "YSRBRA",
                                         "YNUMBER", "YSTRING", "VNAME", "unit", "@1", "prog_head", "@2", "mod_head", "@3", "decl",
                                         "@4", "@5", "Im_dec", "Ex_dec", "Var_dec", "Ar_dec", "@6", "@7", "@8", "@9",
                                         "p_head", "@10", "@11", "p_decl", "p_Var_dec", "p_Arr_dec", "@12", "@13", "@14", "@15",
                                         "p_block", "@16", "block", "@17", "stat_list", "stat", "@18", "@19", "@20", "@21",
                                         "@22", "@23", "@24", "@25", "@26", "@27", "@28", "@29", "@30", "@31",
                                         "@32", "@33", "@34", "@35", "@36", "iden", "cond_stat", "@37", "@38", "@39",
                                         "@40", "@41", "@42", "@43", "assign", "@44", "expr", "@45", "@46", "@47",
                                         "@48", "@49", "variable", "@50", "var_ref", "@51", "@52", ""};
#endif

static const short yyr1[] = {     0,
                                  44, 45, 44, 44, 47, 46, 46, 49, 48, 48,
                                  50, 50, 50, 51, 50, 52, 50, 50, 50, 53,
                                  53, 53, 54, 54, 54, 55, 55, 55, 57, 58,
                                  56, 59, 60, 56, 56, 62, 63, 61, 61, 64,
                                  64, 64, 65, 65, 65, 67, 68, 66, 69, 70,
                                  66, 66, 72, 71, 71, 74, 73, 73, 75, 75,
                                  76, 76, 77, 78, 76, 79, 80, 76, 81, 82,
                                  76, 83, 84, 76, 85, 76, 86, 87, 88, 89,
                                  90, 76, 91, 92, 93, 76, 94, 95, 76, 76,
                                  96, 96, 98, 97, 99, 97, 100, 97, 101, 97,
                                  102, 97, 103, 97, 104, 97, 97, 106, 105, 108,
                                  107, 109, 107, 110, 107, 111, 107, 112, 107, 107,
                                  107, 113, 114, 113, 115, 116, 117, 115};

static const short yyr2[] = {     0,
                                  5, 0, 6, 2, 0, 3, 3, 0, 3, 3,
                                  0, 4, 4, 0, 5, 0, 5, 6, 1, 1,
                                  3, 1, 1, 3, 1, 1, 3, 1, 0, 0,
                                  6, 0, 0, 8, 1, 0, 0, 7, 1, 0,
                                  4, 4, 1, 3, 1, 0, 0, 6, 0, 0,
                                  8, 1, 0, 4, 1, 0, 4, 1, 1, 2,
                                  2, 2, 0, 0, 8, 0, 0, 7, 0, 0,
                                  7, 0, 0, 7, 0, 6, 0, 0, 0, 0,
                                  0, 11, 0, 0, 0, 7, 0, 0, 6, 2,
                                  1, 1, 0, 4, 0, 4, 0, 4, 0, 4,
                                  0, 4, 0, 4, 0, 4, 1, 0, 4, 0,
                                  4, 0, 4, 0, 4, 0, 4, 0, 4, 1,
                                  1, 1, 0, 5, 1, 0, 0, 6};

static const short yydefact[] = {     0,
                                      0, 0, 0, 4, 0, 8, 0, 0, 5, 0,
                                      0, 0, 19, 0, 0, 0, 0, 0, 2, 0,
                                      0, 0, 10, 9, 35, 29, 0, 25, 23, 0,
                                      22, 20, 0, 39, 36, 40, 28, 26, 0, 0,
                                      7, 6, 58, 56, 0, 0, 16, 0, 0, 0,
                                      0, 0, 0, 0, 0, 0, 14, 0, 0, 0,
                                      1, 0, 0, 32, 13, 24, 12, 21, 0, 52,
                                      46, 0, 45, 43, 0, 55, 53, 0, 0, 27,
                                      3, 0, 87, 0, 77, 0, 66, 69, 83, 72,
                                      75, 125, 0, 0, 0, 0, 30, 17, 0, 37,
                                      0, 40, 0, 40, 0, 0, 0, 15, 90, 0,
                                      63, 0, 61, 0, 0, 0, 0, 0, 0, 57,
                                      60, 62, 108, 0, 0, 0, 0, 42, 49, 41,
                                      44, 0, 18, 0, 0, 107, 93, 120, 122, 78,
                                      0, 121, 0, 0, 84, 0, 0, 127, 0, 31,
                                      33, 0, 47, 0, 54, 88, 0, 0, 0, 0,
                                      0, 95, 114, 112, 116, 118, 103, 105, 99, 101,
                                      97, 67, 70, 0, 73, 91, 92, 0, 0, 110,
                                      109, 0, 38, 0, 0, 0, 64, 0, 0, 0,
                                      79, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                      0, 0, 0, 85, 0, 0, 0, 34, 48, 50,
                                      89, 0, 94, 111, 0, 0, 96, 115, 113, 117,
                                      119, 104, 106, 100, 102, 98, 0, 0, 0, 0,
                                      76, 128, 0, 0, 124, 80, 68, 71, 86, 74,
                                      51, 65, 0, 81, 0, 82, 0, 0, 0};

static const short yydefgoto[] = {   247,
                                     40, 10, 21, 7, 12, 19, 79, 63, 33, 30,
                                     39, 27, 46, 124, 99, 182, 36, 53, 126, 56,
                                     75, 72, 101, 184, 154, 233, 78, 106, 45, 60,
                                     93, 94, 135, 212, 114, 202, 115, 203, 117, 205,
                                     118, 112, 161, 216, 243, 245, 116, 174, 229, 110,
                                     186, 178, 140, 158, 192, 201, 199, 200, 197, 198,
                                     95, 149, 141, 159, 194, 193, 195, 196, 142, 160,
                                     96, 119, 179};

static const short yypact[] = {    98,
                                   -24, 2, 3, -32768, -15, -32768, 102, -3, -32768, 115,
                                   26, 43, -32768, 5, 6, 9, 29, 30, -32768, 49,
                                   60, 15, -32768, -32768, -32768, -32768, 55, -32768, -32768, 81,
                                   -32768, -32768, 103, -32768, -32768, 8, -32768, -32768, 114, 42,
                                   -32768, -32768, -32768, -32768, 62, 75, -32768, 58, 89, 79,
                                   89, 82, 96, 32, 34, 119, -32768, 88, 100, 66,
                                   -32768, 135, 89, -32768, -32768, -32768, -32768, -32768, 112, -32768,
                                   -32768, 137, -32768, -32768, 144, -32768, -32768, 116, 89, -32768,
                                   -32768, 146, -32768, 134, -32768, 153, -32768, -32768, -32768, -32768,
                                   -32768, 140, 172, 4, 156, 159, -32768, -32768, 147, -32768,
                                   148, 8, 141, 8, 142, 66, 89, -32768, -32768, 66,
                                   -32768, 1, -32768, 152, 157, 1, 158, 160, 151, -32768,
                                   -32768, -32768, -32768, 154, 155, 161, 162, -32768, -32768, -32768,
                                   -32768, 184, -32768, 187, 166, -32768, -32768, -32768, 163, -32768,
                                   108, -32768, 164, 165, -32768, 164, 130, -32768, 53, -32768,
                                   -32768, 173, -32768, 167, -32768, -32768, 164, 1, 53, 170,
                                   181, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768,
                                   -32768, -32768, -32768, 194, -32768, -32768, -32768, 169, 53, -32768,
                                   138, 171, -32768, 174, 175, 179, -32768, 178, 129, 53,
                                   -32768, 53, 53, 53, 53, 53, 53, 53, 53, 53,
                                   53, 180, 183, -32768, 185, 188, 120, -32768, -32768, -32768,
                                   -32768, 186, -32768, -32768, 124, 66, 138, 145, 145, -32768,
                                   -32768, 138, 138, 138, 138, 138, 195, 196, 66, 197,
                                   -32768, -32768, 189, 198, -32768, -32768, -32768, -32768, -32768, -32768,
                                   -32768, -32768, 212, -32768, 66, -32768, 205, 224, -32768};

static const short yypgoto[] = {-32768,
                                -32768, -32768, -32768, -32768, -32768, -10, -32768, -32768, -32768, -32768,
                                -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -13,
                                -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768,
                                -72, -179, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768,
                                -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768,
                                -32768, -32768, -80, -32768, -32768, -32768, -32768, -32768, -32768, -32768,
                                -32768, -32768, -136, -32768, -32768, -32768, -32768, -32768, -32768, -32768,
                                -128, -32768, -32768};


#define YYLAST      229


static const short yytable[] = {    22,
                                    4, 136, 5, 8, 82, 25, 28, 83, 84, 31,
                                    54, -59, 181, 85, 172, 43, 86, 175, 44, 87,
                                    88, 121, 189, 89, 90, 91, 55, 11, 187, 34,
                                    37, 137, 70, 132, 73, 145, 236, 134, 65, 20,
                                    67, 138, 207, 139, 6, 9, 92, 26, 29, 239,
                                    23, 32, 98, 215, 59, 217, 218, 219, 220, 221,
                                    222, 223, 224, 225, 226, 246, 82, 24, 108, 83,
                                    84, 35, 38, 41, 71, 85, 74, 188, 86, 47,
                                    48, 87, 88, 180, 42, 89, 90, 91, 128, 13,
                                    130, 14, -11, 138, 61, 139, 133, 15, 1, 16,
                                    64, -11, 13, 17, 14, 49, 50, 18, 92, 2,
                                    15, 3, 16, 62, -11, 13, 17, 14, -11, 76,
                                    18, 66, 77, 15, 68, 16, 69, 51, 52, 17,
                                    80, 162, 81, 18, 163, 164, 165, 166, 57, 58,
                                    107, 167, 168, 169, 170, 171, 163, 164, 165, 166,
                                    163, 164, 165, 166, 100, 163, 164, 165, 166, 232,
                                    214, 102, 103, 235, 163, 164, 165, 166, 104, 105,
                                    109, 176, 177, 165, 166, 97, 111, 113, -126, 120,
                                    122, 123, 143, 129, 131, 125, 127, 144, 146, 148,
                                    147, 155, 152, 150, 156, 151, 157, 183, 191, 204,
                                    206, -123, 153, 211, 248, 185, 92, 173, 190, 213,
                                    208, 227, 231, 209, 228, 210, 230, 234, 244, 237,
                                    238, 240, 242, 249, 0, 0, 0, 0, 241};

static const short yycheck[] = {    10,
                                    25, 1, 1, 1, 1, 1, 1, 4, 5, 1,
                                    3, 8, 149, 10, 143, 1, 13, 146, 4, 16,
                                    17, 94, 159, 20, 21, 22, 19, 43, 157, 1,
                                    1, 31, 1, 106, 1, 116, 216, 110, 49, 43,
                                    51, 41, 179, 43, 43, 43, 43, 43, 43, 229,
                                    25, 43, 63, 190, 13, 192, 193, 194, 195, 196,
                                    197, 198, 199, 200, 201, 245, 1, 25, 79, 4,
                                    5, 43, 43, 25, 43, 10, 43, 158, 13, 25,
                                    26, 16, 17, 31, 25, 20, 21, 22, 102, 1,
                                    104, 3, 4, 41, 33, 43, 107, 9, 1, 11,
                                    43, 13, 1, 15, 3, 25, 26, 19, 43, 12,
                                    9, 14, 11, 39, 13, 1, 15, 3, 4, 1,
                                    19, 43, 4, 9, 43, 11, 31, 25, 26, 15,
                                    43, 24, 33, 19, 27, 28, 29, 30, 25, 26,
                                    25, 34, 35, 36, 37, 38, 27, 28, 29, 30,
                                    27, 28, 29, 30, 43, 27, 28, 29, 30, 40,
                                    32, 25, 26, 40, 27, 28, 29, 30, 25, 26,
                                    25, 42, 43, 29, 30, 41, 43, 25, 39, 8,
                                    25, 23, 31, 43, 43, 39, 39, 31, 31, 39,
                                    31, 8, 32, 40, 8, 41, 31, 25, 18, 6,
                                    32, 39, 41, 25, 0, 39, 43, 43, 39, 32,
                                    40, 32, 25, 40, 32, 41, 32, 32, 7, 25,
                                    25, 25, 25, 0, -1, -1, -1, -1, 40};
/* -*-C-*-  Note some compilers choke on comments on `#line' lines.  */
#line 3 "/usr/local/lib/bison.simple"

/* Skeleton output parser for bison,
   Copyright (C) 1984, 1989, 1990 Bob Corbett and Richard Stallman

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 1, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */


#ifndef alloca
#ifdef __GNUC__
#define alloca __builtin_alloca
#else /* Not GNU C.  */
#if (!defined (__STDC__) && defined (sparc)) || defined (__sparc__)
#include <alloca.h>
#else /* Not sparc */
#ifdef MSDOS
#include <malloc.h>
#endif /* MSDOS */
#endif /* Not sparc.  */
#endif /* Not GNU C.  */
#endif /* alloca not defined.  */

/* This is the parser code that is written into each bison parser
   when the %semantic_parser declaration is not specified in the grammar.
   It was written by Richard Stallman by simplifying the hairy parser
   used when %semantic_parser is specified.  */

/* Note: there must be only one dollar sign in this file.
   It is replaced by the list of actions, each action
   as one case of the switch.  */

#define yyerrok     (yyerrstatus = 0)
#define yyclearin   (yychar = YYEMPTY)
#define YYEMPTY     -2
#define YYEOF       0
#define YYACCEPT    return(0)
#define YYABORT     return(1)
#define YYERROR     goto yyerrlab1
/* Like YYERROR except do call yyerror.
   This remains here temporarily to ease the
   transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */
#define YYFAIL      goto yyerrlab
#define YYRECOVERING()  (!!yyerrstatus)
#define YYBACKUP(token, value) \
    do                              \
    if (yychar == YYEMPTY && yylen == 1)              \
    { yychar = (token), yylval = (value);           \
      yychar1 = YYTRANSLATE (yychar);               \
      YYPOPSTACK;                       \
      goto yybackup;                        \
    }                               \
    else                              \
    { yyerror ("syntax error: cannot back up"); YYERROR; }  \
    while (0)

#define YYTERROR    1
#define YYERRCODE   256

#ifndef YYPURE
#define YYLEX       yylex()
#endif

#ifdef YYPURE
#ifdef YYLSP_NEEDED
#define YYLEX       yylex(&yylval, &yylloc)
#else
#define YYLEX       yylex(&yylval)
#endif
#endif

/* If nonreentrant, generate the variables here */

#ifndef YYPURE

int yychar;         /*  the lookahead symbol		*/
YYSTYPE yylval;         /*  the semantic value of the		*/
/*  lookahead symbol			*/

#ifdef YYLSP_NEEDED
YYLTYPE yylloc;         /*  location data for the lookahead	*/
/*  symbol				*/
#endif

int yynerrs;            /*  number of parse errors so far       */
#endif  /* not YYPURE */

#if YYDEBUG != 0
int yydebug;            /*  nonzero means print parse trace	*/
/* Since this is uninitialized, it does not stop multiple parsers
   from coexisting.  */
#endif

/*  YYINITDEPTH indicates the initial size of the parser's stacks	*/

#ifndef YYINITDEPTH
#define YYINITDEPTH 200
#endif

/*  YYMAXDEPTH is the maximum size the stacks can grow to
    (effective only if the built-in stack extension method is used).  */

#if YYMAXDEPTH == 0
#undef YYMAXDEPTH
#endif

#ifndef YYMAXDEPTH
#define YYMAXDEPTH 10000
#endif

#ifndef __cplusplus

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_bcopy (from, to, count)
char *from;
char *to;
int count;
{
    register char *f = from;
    register char *t = to;
    register int i = count;

    while (i-- > 0)
        *t++ = *f++;
}

#else /* __cplusplus */

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_bcopy (char *from, char *to, int count)
{
    register char *f = from;
    register char *t = to;
    register int i = count;

    while (i-- > 0)
        *t++ = *f++;
}

#endif

#line 160 "/usr/local/lib/bison.simple"
int
yyparse()
{
    register int yystate;
    register int yyn;
    register short *yyssp;
    register YYSTYPE *yyvsp;
    int yyerrstatus; /*  number of tokens to shift before error messages enabled */
    int yychar1;    /*  lookahead token as an internal (translated) token number */

    short yyssa[YYINITDEPTH]; /*  the state stack			*/
    YYSTYPE yyvsa[YYINITDEPTH]; /*  the semantic value stack		*/

    short *yyss = yyssa;    /*  refer to the stacks thru separate pointers */
    YYSTYPE *yyvs = yyvsa;  /*  to allow yyoverflow to reallocate them elsewhere */

#ifdef YYLSP_NEEDED
    YYLTYPE *yyls = yylsa;
    YYLTYPE *yylsp;
    YYLTYPE yylsa[YYINITDEPTH]; /*  the location stack			*/

#define YYPOPSTACK   (yyvsp--, yysp--, yylsp--)
#else
#define YYPOPSTACK   (yyvsp--, yysp--)
#endif

    int yystacksize = YYINITDEPTH;

#ifdef YYPURE
    int yychar;
    YYSTYPE yylval;
    int yynerrs;
#ifdef YYLSP_NEEDED
    YYLTYPE yylloc;
#endif
#endif

    YYSTYPE yyval;      /*  the variable used to return		*/
    /*  semantic values from the action	*/
    /*  routines				*/

    int yylen;

#if YYDEBUG != 0
    if (yydebug)
        fprintf(stderr, "Starting parse\n");
#endif

    yystate = 0;
    yyerrstatus = 0;
    yynerrs = 0;
    yychar = YYEMPTY;   /* Cause a token to be read.  */

    /* Initialize stack pointers.
       Waste one element of value and location stack
       so that they stay on the same level as the state stack.  */

    yyssp = yyss - 1;
    yyvsp = yyvs;
#ifdef YYLSP_NEEDED
    yylsp = yyls;
#endif

/* Push a new state, which is found in  yystate  .  */
/* In all cases, when you get here, the value and location stacks
   have just been pushed. so pushing a state here evens the stacks.  */
yynewstate:

    *++yyssp = yystate;

    if (yyssp >= yyss + yystacksize - 1)
    {
        /* Give user a chance to reallocate the stack */
        /* Use copies of these so that the &'s don't force the real ones into memory. */
        YYSTYPE *yyvs1 = yyvs;
        short *yyss1 = yyss;
#ifdef YYLSP_NEEDED
        YYLTYPE *yyls1 = yyls;
#endif

        /* Get the current used size of the three stacks, in elements.  */
        int size = yyssp - yyss + 1;

#ifdef yyoverflow
        /* Each stack pointer address is followed by the size of
           the data in use in that stack, in bytes.  */
        yyoverflow("parser stack overflow",
                   &yyss1, size * sizeof (*yyssp),
                   &yyvs1, size * sizeof (*yyvsp),
#ifdef YYLSP_NEEDED
                   &yyls1, size * sizeof (*yylsp),
#endif
                   &yystacksize);

        yyss = yyss1; yyvs = yyvs1;
#ifdef YYLSP_NEEDED
        yyls = yyls1;
#endif
#else /* no yyoverflow */
      /* Extend the stack our own way.  */
        if (yystacksize >= YYMAXDEPTH)
        {
            yyerror("parser stack overflow");
            return 2;
        }
        yystacksize *= 2;
        if (yystacksize > YYMAXDEPTH)
            yystacksize = YYMAXDEPTH;
        yyss = (short *) alloca (yystacksize * sizeof (*yyssp));
        __yy_bcopy ((char *)yyss1, (char *)yyss, size * sizeof (*yyssp));
        yyvs = (YYSTYPE *) alloca (yystacksize * sizeof (*yyvsp));
        __yy_bcopy ((char *)yyvs1, (char *)yyvs, size * sizeof (*yyvsp));
#ifdef YYLSP_NEEDED
        yyls = (YYLTYPE *) alloca (yystacksize * sizeof (*yylsp));
        __yy_bcopy ((char *)yyls1, (char *)yyls, size * sizeof (*yylsp));
#endif
#endif /* no yyoverflow */

        yyssp = yyss + size - 1;
        yyvsp = yyvs + size - 1;
#ifdef YYLSP_NEEDED
        yylsp = yyls + size - 1;
#endif

#if YYDEBUG != 0
        if (yydebug)
            fprintf(stderr, "Stack size increased to %d\n", yystacksize);
#endif

        if (yyssp >= yyss + yystacksize - 1)
            YYABORT;
    }

#if YYDEBUG != 0
    if (yydebug)
        fprintf(stderr, "Entering state %d\n", yystate);
#endif

yybackup:

/* Do appropriate processing given the current state.  */
/* Read a lookahead token if we need one and don't already have one.  */
/* yyresume: */

    /* First try to decide what to do without reference to lookahead token.  */

    yyn = yypact[yystate];
    if (yyn == YYFLAG)
        goto yydefault;

    /* Not known => get a lookahead token if don't already have one.  */

    /* yychar is either YYEMPTY or YYEOF
       or a valid token in external form.  */

    if (yychar == YYEMPTY)
    {
#if YYDEBUG != 0
        if (yydebug)
            fprintf(stderr, "Reading a token: ");
#endif
        yychar = YYLEX;
    }

    /* Convert token to internal form (in yychar1) for indexing tables with */

    if (yychar <= 0)    /* This means end of input. */
    {
        yychar1 = 0;
        yychar = YYEOF;     /* Don't call YYLEX any more */

#if YYDEBUG != 0
        if (yydebug)
            fprintf(stderr, "Now at end of input.\n");
#endif
    }
    else
    {
        yychar1 = YYTRANSLATE(yychar);

#if YYDEBUG != 0
        if (yydebug)
            fprintf(stderr, "Next token is %d (%s)\n", yychar, yytname[yychar1]);
#endif
    }

    yyn += yychar1;
    if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != yychar1)
        goto yydefault;

    yyn = yytable[yyn];

    /* yyn is what to do for this token type in this state.
       Negative => reduce, -yyn is rule number.
       Positive => shift, yyn is new state.
         New state is final state => don't bother to shift,
         just return success.
       0, or most negative number => error.  */

    if (yyn < 0)
    {
        if (yyn == YYFLAG)
            goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
    }
    else if (yyn == 0)
        goto yyerrlab;

    if (yyn == YYFINAL)
        YYACCEPT;

    /* Shift the lookahead token.  */

#if YYDEBUG != 0
    if (yydebug)
        fprintf(stderr, "Shifting token %d (%s), ", yychar, yytname[yychar1]);
#endif

    /* Discard the token being shifted unless it is eof.  */
    if (yychar != YYEOF)
        yychar = YYEMPTY;

    *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
    *++yylsp = yylloc;
#endif

    /* count tokens shifted since error; after three, turn off error status.  */
    if (yyerrstatus)
        yyerrstatus--;

    yystate = yyn;
    goto yynewstate;

/* Do the default action for the current state.  */
yydefault:

    yyn = yydefact[yystate];
    if (yyn == 0)
        goto yyerrlab;

/* Do a reduction.  yyn is the number of a rule to reduce with.  */
yyreduce:
    yylen = yyr2[yyn];
    yyval = yyvsp[1-yylen]; /* implement default value of the action */

#if YYDEBUG != 0
    if (yydebug)
    {
        int i;

        fprintf (stderr, "Reducing via rule %d (line %d), ",
                 yyn, yyrline[yyn]);

        /* Print the symboles being reduced, and their result.  */
        for (i = yyprhs[yyn]; yyrhs[i] > 0; i++)
            fprintf (stderr, "%s ", yytname[yyrhs[i]]);
        fprintf (stderr, " -> %s\n", yytname[yyr1[yyn]]);
    }
#endif


    switch (yyn) {

    case 1:
#line 116 "gram.y"
        {
            if (!l_list)
            {
                printf("Program Compilation completed.");
                printf("Total errors = %d\n", err_cnt+ill_cnt);
            }
#ifdef TRACE
            d_print(dbase);
            e_print(ebase);
            lv_print(lvbase);
            r_print(rbase);
            printf("Dtab size= %d Etab size = %d\n", d_size, e_size);
            printf("Rtab size= %d Itab size = %d\n", r_size, i_size);
#endif
            ;
            break;
        }
    case 2:
#line 132 "gram.y"
        {
            exp_tst();
            ;
            break;
        }
    case 3:
#line 136 "gram.y"
        {
            if (!l_list)
            {
                printf("Module Compilation completed.");
                printf("Total errors = %d\n", err_cnt+ill_cnt);
            }
#ifdef TRACE
            d_print(dbase);
            e_print(ebase);
            printf("Dtab size = %d Etab size = %d\n", d_size, e_size);
#endif TRACE
            ;
            break;
        }
    case 4:
#line 149 "gram.y"
        {
            yyError("Invalid Starting line ");
            ;
            break;
        }
    case 5:
#line 156 "gram.y"
        {
            strncpy(pname, yytext, MAXVAR);
            upd_magic();
            prog_all();
            if (s_flag)
            {
                as_inst_pr(".start", pname);
                as_line_pr();
                /*
                    Always add to assembly printout the standard I/O imports
                 */
                as_inst_pr(".import", "read");
                as_inst_pr(".import", "write");
                as_inst_pr(".import", "readstr");
                as_inst_pr(".import", "writestr");
            }
            if (!fatal && c_flag)
            {
                c_put("#include <stdio.h>\n\n");
                c_put("/*\n");
                c_put(" * 'C' translation of 'A' program named ");
                c_put(yytext);
                c_put_nl();
                c_put(" */\n\n");
            }
            if (l_list)
                put_ref(pname, "D");
            ;
            break;
        }
    case 7:
#line 184 "gram.y"
        {
            yyError("Malformed PROGRAM statement");
            ;
            break;
        }
    case 8:
#line 190 "gram.y"
        {
            upd_magic();
            if (s_flag)
            {
                as_inst_pr(".module", yytext);
                as_line_pr();
                /*
                    Always add to assembly printout the standard I/O imports
                 */
                as_inst_pr(".import", "read");
                as_inst_pr(".import", "write");
                as_inst_pr(".import", "readstr");
                as_inst_pr(".import", "writestr");
            }
            if (l_list)
                put_ref(yytext, "D");
            ;
            break;
        }
    case 10:
#line 208 "gram.y"
        {
            yyError("Malformed MODULE statement");
            ;
            break;
        }
    case 14:
#line 219 "gram.y"
        {
            if (!fatal && c_flag)
            {
                c_put(";");
                c_put_nl();
            }
            ;
            break;
        }
    case 16:
#line 228 "gram.y"
        {
            if (!fatal && c_flag)
            {
                c_put(";");
                c_put_nl();
            }
            ;
            break;
        }
    case 19:
#line 239 "gram.y"
        {
            yyError("Malformed DECLARATIONS");
            ;
            break;
        }
    case 20:
#line 250 "gram.y"
        {
            if (!fatal)
                imp_all();
            if (!fatal && s_flag)
            {
                as_inst_pr(".import", yytext);
            }
            if (l_list)
                put_ref(yytext, "D");
            ;
            break;
        }
    case 21:
#line 260 "gram.y"
        {
            if (!fatal)
                imp_all();
            if (!fatal && s_flag)
            {
                as_inst_pr(".import", yytext);
            }
            if (l_list)
                put_ref(yytext, "D");
            ;
            break;
        }
    case 22:
#line 270 "gram.y"
        {
            yyError("Malformed IMPORT declaration");
            ;
            break;
        }
    case 23:
#line 280 "gram.y"
        {
            if (!fatal)
                exp_all();
            if (!fatal && s_flag)
            {
                as_inst_pr(".export", yytext);
            }
            if (l_list)
                put_ref(yytext, "D");
            ;
            break;
        }
    case 24:
#line 290 "gram.y"
        {
            if (!fatal)
                exp_all();
            if (!fatal && s_flag)
            {
                as_inst_pr(".export", yytext);
            }
            if (l_list)
                put_ref(yytext, "D");
            ;
            break;
        }
    case 25:
#line 300 "gram.y"
        {
            yyError("Malformed EXPORT declaration");
            ;
            break;
        }
    case 26:
#line 310 "gram.y"
        {
            if (!fatal)
                var_all();
            if (!fatal && s_flag )
            {
                as_stat(yytext, ".word", "1");
            }
            if (!fatal && c_flag)
            {
                c_put("int");
                c_put_tab(1);
                c_put(yytext);
            }
            if (l_list)
                put_ref(yytext, "D");
            ;
            break;
        }
    case 27:
#line 325 "gram.y"
        {
            if (!fatal)
                var_all();
            if (!fatal && c_flag)
            {
                c_put(", ");
                c_put(yytext);
            }
            if (!fatal && s_flag )
            {
                as_stat(yytext, ".word", "1");
            }
            if (l_list)
                put_ref(yytext, "D");
            ;
            break;
        }
    case 28:
#line 339 "gram.y"
        {
            yyError("Malformed VAR declaration");
            ;
            break;
        }
    case 29:
#line 349 "gram.y"
        {
            if (!fatal)
                strncpy(tsave, yytext, MAXVAR);
            if (l_list)
                put_ref(yytext, "D");
            if (!fatal && c_flag)
            {
                c_put("int");
                c_put_tab(1);
                c_put(yytext);
            }
            ;
            break;
        }
    case 30:
#line 359 "gram.y"
        {
            if (!fatal)
                array_all();
            if (!fatal && s_flag )
            {
                as_stat(tsave, ".word", yytext);
            }
            if (!fatal && c_flag)
            {
                c_put("[");
                c_put(yytext);
                c_put("]");
            }
            ;
            break;
        }
    case 32:
#line 374 "gram.y"
        {
            if (!fatal)
                strncpy(tsave, yytext, MAXVAR);
            if (l_list)
                put_ref(yytext, "D");
            if (!fatal && c_flag)
            {
                c_put(", ");
                c_put(yytext);
            }
            ;
            break;
        }
    case 33:
#line 383 "gram.y"
        {
            if (!fatal)
                array_all();
            if (!fatal && s_flag )
            {
                as_stat(tsave, ".word", yytext);
            }
            if (!fatal && c_flag)
            {
                c_put("[");
                c_put(yytext);
                c_put("]");
            }
            ;
            break;
        }
    case 35:
#line 397 "gram.y"
        {
            yyError("Malformed ARRAY declaration");
            ;
            break;
        }
    case 36:
#line 403 "gram.y"
        {
            if (!fatal)
            {
                strncpy(procname, yytext, MAXVAR);
                if (l_list)
                    put_ref(procname, "D");
                proc_all();
                if ( s_flag )
                {
                    as_line_pr();
                    as_label_pr(yytext);
                }
            }
            ;
            break;
        }
    case 37:
#line 416 "gram.y"
        {
            if (!fatal )
                strncpy(p_param, yytext, MAXVAR);
            ;
            break;
        }
    case 39:
#line 426 "gram.y"
        {
            yyError("Malformed PROCEDURE head");
            ;
            break;
        }
    case 43:
#line 440 "gram.y"
        {
            if (!fatal)
            {
                lvar_all();
                ia_add(SP_ALLOC, 1);
                act_sp += 1;
                if (s_flag)
                {
                    as_inst_pr("spalloc", "1");
                }
            }
            ;
            break;
        }
    case 44:
#line 452 "gram.y"
        {
            if (!fatal)
            {
                lvar_all();
                ia_add(SP_ALLOC, 1);
                act_sp += 1;
                if (s_flag)
                {
                    as_inst_pr("spalloc", "1");
                }
            }
            ;
            break;
        }
    case 45:
#line 464 "gram.y"
        {
            yyError("Malformed VAR declaration in PROCEDURE");
            ;
            break;
        }
    case 46:
#line 469 "gram.y"
        {
            if (!fatal)
                strncpy(tsave, yytext, MAXVAR);
            ;
            break;
        }
    case 47:
#line 473 "gram.y"
        {
            if (!fatal)
            {
                larr_all();
                ia_add(SP_ALLOC, atoi(yytext));
                act_sp += atoi(yytext);
                if (s_flag)
                {
                    as_inst_pr("spalloc", yytext);
                }
            }
            ;
            break;
        }
    case 49:
#line 487 "gram.y"
        {
            if (!fatal)
                strncpy(tsave, yytext, MAXVAR);
            ;
            break;
        }
    case 50:
#line 491 "gram.y"
        {
            if (!fatal)
            {
                larr_all();
                ia_add(SP_ALLOC, atoi(yytext));
                act_sp += atoi(yytext);
                if (s_flag)
                {
                    as_inst_pr("spalloc", yytext);
                }
            }
            ;
            break;
        }
    case 52:
#line 505 "gram.y"
        {
            yyError("Malformed ARRAY declaration in PROCEDURE");
            ;
            break;
        }
    case 53:
#line 512 "gram.y"
        { if (!fatal)
              in_proc = 1;
          ;
          break;}
    case 54:
#line 515 "gram.y"
        {
            if (!fatal)
            {
                if ( lv_size != 0 )
                {
                    ia_add(SP_FREE, lvtwo->addr);
                    if (s_flag)
                    {
                        as_i_int("spfree", lvtwo->addr);
                    }
                    act_sp-=lvtwo->addr;
                    lv_free(lvbase);
                    lv_size = 0;
                    lv_first = 1;
                }
                ib_add(RET);
                in_proc = 0;
                if (s_flag)
                {
                    as_inst_pr("ret", "");
                }
            }
            ;
            break;
        }
    case 55:
#line 537 "gram.y"
        {
            yyError("Proc block : Syntax Error");
            ;
            break;
        }
    case 56:
#line 548 "gram.y"
        {
            /* test to find unresolved exports */

            exp_tst();

            if (!fatal)
            {
                /* fill program entry with correct address */
                fill_p_add();
                if (s_flag)
                {
                    as_line_pr();
                    as_label_pr(pname);
                }
                if (c_flag)
                {
                    n_tabs++; /* tab level for c generation */
                    c_put("\nmain()\n");
                    c_put("{\n");
                }
            }
            ;
            break;
        }
    case 57:
#line 569 "gram.y"
        {
            if (!fatal)
            {
                /* Add stop instruction at end of program */

                ib_add(STOP);
                if (s_flag)
                {
                    as_inst_pr("stop", "");
                    as_inst_pr(".end", "");
                }
                if (!fatal && c_flag)
                {
                    c_put("}\n");
                }
            }
            ;
            break;
        }
    case 58:
#line 586 "gram.y"
        {
            yyError("Syntax Error");
            ;
            break;
        }
    case 61:
#line 597 "gram.y"
        {
            if (!fatal && c_flag)
            {
                c_put(";\n");
            }
            ;
            break;
        }
    case 62:
#line 604 "gram.y"
        {
            if (!fatal && c_flag)
            {
                c_put(";\n");
            }
            ;
            break;
        }
    case 63:
#line 611 "gram.y"
        {
            if (!fatal)
            {
                strncpy(tsave, yytext, MAXVAR);
                if (c_flag)
                {
                    c_put(yytext);
                    c_put(" ( ");
                }
            }
            if (l_list)
                put_ref(tsave, "U");
            ;
            break;
        }
    case 64:
#line 622 "gram.y"
        {
/*
 *    CALL PROCEDURE
 */

            if (!fatal)
                call();

            ;
            break;
        }
    case 65:
#line 631 "gram.y"
        {
            if (!fatal && c_flag)
            {
                c_put(" );\n");
            }
            ;
            break;
        }
    case 66:
#line 640 "gram.y"
        {
            if (!fatal)
                io_all();
            if (l_list)
                put_ref("read", "U");
            if (!fatal && c_flag)
            {
                c_put("scanf(\"\%d\\n\", ");
            }
            ;
            break;
        }
    case 67:
#line 650 "gram.y"
        {
            if (!fatal)
            {
                strcpy(tsave, "read");
                call();
            }
            ;
            break;
        }
    case 68:
#line 658 "gram.y"
        {
            if (!fatal && c_flag)
            {
                c_put(");\n");
            }
            ;
            break;
        }
    case 69:
#line 666 "gram.y"
        {
            if (!fatal)
                io_all();
            if (l_list)
                put_ref("readstr", "U");
            ;
            break;
        }
    case 70:
#line 672 "gram.y"
        {
            if (!fatal)
            {
                ident();
                rdcall();
                if (c_flag)
                {
                    yyError("Unable to create C code for this statement");
/*
            c_put_tab(n_tabs);
            c_put("gets ( ");
            c_put("(char *)&");
            c_put(yytext);
            c_put("[0]");
            c_put(" );\n");
 */
                }
            }
            ;
            break;
        }
    case 72:
#line 694 "gram.y"
        {
            if (!fatal)
            {
                io_all();
                if (c_flag)
                {
                    c_put("printf(\"\%d\\n\", ");
                }
            }
            if (l_list)
                put_ref("write", "U");
            ;
            break;
        }
    case 73:
#line 705 "gram.y"
        {
            if (!fatal)
            {
                strcpy(tsave, "write");
                call();
            }
            ;
            break;
        }
    case 74:
#line 713 "gram.y"
        {
            if (!fatal && c_flag)
            {
                c_put(");\n");
            }
            ;
            break;
        }
    case 75:
#line 721 "gram.y"
        {
            if (!fatal)
            {
                io_all();
                if (c_flag)
                {
                    yyError("Unable to create C code for this statement");
/*
            c_put_tab(n_tabs);
            c_put("puts (");
 */
                }
            }
            if (l_list)
                put_ref("writestr", "U");
            ;
            break;
        }
    case 76:
#line 736 "gram.y"
        {
            if (!fatal && c_flag)
            {
                c_put(");\n");
            }
            ;
            break;
        }
    case 77:
#line 745 "gram.y"
        {
            if (!fatal && c_flag)
            {
                c_put("if ( ");
            }
            ;
            break;
        }
    case 78:
#line 751 "gram.y"
        {
            if (!fatal)
                i_push(i_cnt-1);
            ;
            break;
        }
    case 79:
#line 755 "gram.y"
        {
            if (!fatal && c_flag )
            {
                c_put(" ) ");
            }
            ;
            break;
        }
    case 80:
#line 761 "gram.y"
        {
            if (!fatal)
            {
                ia_add(JUMP, 0);
                rel_all("J");
                if (s_flag)
                {
                    l_push(l_cnt);
                    as_inst_pr("jmp", as_make_label(l_cnt));
                    l_cnt++;
                }
            }
            ;
            break;
        }
    case 81:
#line 774 "gram.y"
        {
            if (!fatal)
            {
                if (s_flag)
                {
                    as_label_pr(as_make_label(l_prev()));
                }
                if (c_flag)
                {
                    c_put("else");
                }
                itab[i_pop()] = i_cnt;
                i_push(i_cnt-1);
            }
            ;
            break;
        }
    case 82:
#line 788 "gram.y"
        {
            if (!fatal)
            {
                if (s_flag)
                {
                    as_label_pr(as_make_label(l_pop()));
                    l_pop();
                }
                if (c_flag)
                {
                    n_tabs--;
                }
                itab[i_pop()] = i_cnt;
            }
            ;
            break;
        }
    case 83:
#line 803 "gram.y"
        {
            if (!fatal)
            {
                /* save this address push(i_cnt) */
                i_push(i_cnt);
                if (s_flag)
                {
                    l_push(l_cnt);
                    as_label_pr(as_make_label(l_cnt));
                    l_cnt++;
                }
                if (c_flag)
                {
                    c_put("while ( ");
                }
            }
            ;
            break;
        }
    case 84:
#line 819 "gram.y"
        {
            /* push address of jmp to be filled */

            if (!fatal)
                i_push(i_cnt-1);
            ;
            break;
        }
    case 85:
#line 825 "gram.y"
        {
            if (!fatal && c_flag)
            {
                c_put(" ) ");
            }
            ;
            break;
        }
    case 86:
#line 831 "gram.y"
        {
            if (!fatal)
            {
                /* fill address  ( pop )  ,*/

                itab[i_pop()] = i_cnt+2;

                /*	jump back to (pop) */

                ia_add(JUMP, i_pop());
                rel_all("J");
                if (s_flag)
                {
                    as_inst_pr("jmp", as_make_label(l_prev()));
                    as_label_pr(as_make_label(l_pop()));
                    l_pop();
                }
            }
            ;
            break;
        }
    case 87:
#line 851 "gram.y"
        {
            if (!fatal && c_flag)
            {
                c_put("{\n");
                n_tabs++;
            }
            ;
            break;
        }
    case 88:
#line 859 "gram.y"
        {
            if (!fatal && c_flag)
            {
                n_tabs--;
                c_put("}\n");
            }
            ;
            break;
        }
    case 90:
#line 868 "gram.y"
        {
            yyError("Malformed STATEMENT");
            ;
            break;
        }
    case 91:
#line 875 "gram.y"
        {
            if (!fatal)
            {
                string();
                if (c_flag)
                {
                    c_put("\"");
                    c_put(yytext);
                    c_put("\"");
                }
            }
            ;
            break;
        }
    case 92:
#line 888 "gram.y"
        {
            if (!fatal)
            {
                if (l_list)
                    put_ref(yytext, "U");
                ident();
                wrcall();
                if (c_flag)
                {
                    c_put("(char *)&");
                    c_put(yytext);
                    c_put("[0]");
                }
            }
            ;
            break;
        }
    case 93:
#line 905 "gram.y"
        {
            if (!fatal && c_flag)
            {
                c_put("(");
            }
            ;
            break;
        }
    case 94:
#line 912 "gram.y"
        {
            if (!fatal && c_flag)
            {
                c_put(")");
            }
            ;
            break;
        }
    case 95:
#line 920 "gram.y"
        {
            if (!fatal && c_flag)
            {
                c_put(" == ");
            }
            ;
            break;
        }
    case 96:
#line 926 "gram.y"
        {
            if (!fatal)
            {
                ib_add(CMP);
                if (in_proc)
                    act_sp -= 2;
                if (s_flag)
                {
                    as_inst_pr("cmp", "");
                    l_push(l_cnt);
                    as_inst_pr("jne", as_make_label(l_cnt));
                    l_cnt++;
                }
                ia_add(JNE, 0);
                rel_all("J");
            }
            ;
            break;
        }
    case 97:
#line 944 "gram.y"
        {
            if (!fatal && c_flag)
            {
                c_put(" != ");
            }
            ;
            break;
        }
    case 98:
#line 950 "gram.y"
        {
            if (!fatal)
            {
                ib_add(CMP);
                if (in_proc)
                    act_sp -= 2;
                if (s_flag)
                {
                    as_inst_pr("cmp", "");
                    l_push(l_cnt);
                    as_inst_pr("jeq", as_make_label(l_cnt));
                    l_cnt++;
                }
                ia_add(JEQ, 0);
                rel_all("J");
            }
            ;
            break;
        }
    case 99:
#line 968 "gram.y"
        {
            if (!fatal && c_flag)
            {
                c_put(" < ");
            }
            ;
            break;
        }
    case 100:
#line 974 "gram.y"
        {
            if (!fatal)
            {
                ib_add(CMP);
                if (in_proc)
                    act_sp -= 2;
                if (s_flag)
                {
                    as_inst_pr("cmp", "");
                    l_push(l_cnt);
                    as_inst_pr("jge", as_make_label(l_cnt));
                    l_cnt++;
                }
                ia_add(JGE, 0);
                rel_all("J");
            }
            ;
            break;
        }
    case 101:
#line 992 "gram.y"
        {
            if (!fatal && c_flag)
            {
                c_put(" > ");
            }
            ;
            break;
        }
    case 102:
#line 998 "gram.y"
        {
            if (!fatal)
            {
                ib_add(CMP);
                if (in_proc)
                    act_sp -= 2;
                if (s_flag)
                {
                    as_inst_pr("cmp", "");
                    l_push(l_cnt);
                    as_inst_pr("jle", as_make_label(l_cnt));
                    l_cnt++;
                }
                ia_add(JLE, 0);
                rel_all("J");
            }
            ;
            break;
        }
    case 103:
#line 1016 "gram.y"
        {
            if (!fatal && c_flag)
            {
                c_put(" <= ");
            }
            ;
            break;
        }
    case 104:
#line 1022 "gram.y"
        {
            if (!fatal)
            {
                ib_add(CMP);
                if (in_proc)
                    act_sp -= 2;
                if (s_flag)
                {
                    as_inst_pr("cmp", "");
                    l_push(l_cnt);
                    as_inst_pr("jgt", as_make_label(l_cnt));
                    l_cnt++;
                }
                ia_add(JGT, 0);
                rel_all("J");
            }
            ;
            break;
        }
    case 105:
#line 1040 "gram.y"
        {
            if (!fatal && c_flag)
            {
                c_put(" >= ");
            }
            ;
            break;
        }
    case 106:
#line 1046 "gram.y"
        {
            if (!fatal)
            {
                ib_add(CMP);
                if (in_proc)
                    act_sp -= 2;
                if (s_flag)
                {
                    as_inst_pr("cmp", "");
                    l_push(l_cnt);
                    as_inst_pr("jlt", as_make_label(l_cnt));
                    l_cnt++;
                }
                ia_add(JLT, 0);
                rel_all("J");
            }
            ;
            break;
        }
    case 107:
#line 1063 "gram.y"
        {
            yyError("Wrong logical operator");
            ;
            break;
        }
    case 108:
#line 1070 "gram.y"
        {
            if (!fatal && c_flag)
            {
                c_put(" = ");
            }
            ;
            break;
        }
    case 109:
#line 1076 "gram.y"
        {
            if (!fatal)
            {
                ib_add(POP_);
                if (in_proc)
                    act_sp -= 2;
                if (s_flag)
                {
                    as_inst_pr("pop*", "");
                }
            }
            ;
            break;
        }
    case 110:
#line 1089 "gram.y"
        {
            if (!fatal && c_flag)
            {
                c_put("(");
            }
            ;
            break;
        }
    case 111:
#line 1095 "gram.y"
        {
            if (!fatal && c_flag)
            {
                c_put(")");
            }
            ;
            break;
        }
    case 112:
#line 1102 "gram.y"
        {
            if (!fatal && c_flag)
            {
                c_put(" + ");
            }
            ;
            break;
        }
    case 113:
#line 1108 "gram.y"
        {
            if (!fatal)
            {
                if (in_proc)
                    act_sp -= 1;
                ib_add(ADD);
                if (s_flag)
                {
                    as_inst_pr("add", "");
                }
            }
            ;
            break;
        }
    case 114:
#line 1120 "gram.y"
        {
            if (!fatal && c_flag)
            {
                c_put(" - ");
            }
            ;
            break;
        }
    case 115:
#line 1126 "gram.y"
        {
            if (!fatal)
            {
                if (in_proc)
                    act_sp -= 1;
                ib_add(SUB);
                if (s_flag)
                {
                    as_inst_pr("sub", "");
                }
            }
            ;
            break;
        }
    case 116:
#line 1138 "gram.y"
        {
            if (!fatal && c_flag)
            {
                c_put(" * ");
            }
            ;
            break;
        }
    case 117:
#line 1144 "gram.y"
        {
            if (!fatal)
            {
                if (in_proc)
                    act_sp -= 1;
                ib_add(MUL);
                if (s_flag)
                {
                    as_inst_pr("mul", "");
                }
            }
            ;
            break;
        }
    case 118:
#line 1156 "gram.y"
        {
            if (!fatal && c_flag)
            {
                c_put(" / ");
            }
            ;
            break;
        }
    case 119:
#line 1162 "gram.y"
        {
            if (!fatal)
            {
                if (in_proc)
                    act_sp -= 1;
                ib_add(DIV);
                if (s_flag)
                {
                    as_inst_pr("div", "");
                }
            }
            ;
            break;
        }
    case 120:
#line 1174 "gram.y"
        {
            if (!fatal)
            {
                if (in_proc)
                    act_sp += 1;
                ia_add(PUSHI, atoi(yytext));
                if (s_flag)
                {
                    as_inst_pr("pushi", yytext);
                }
                if (c_flag)
                {
                    c_put(yytext);
                }
            }
            ;
            break;
        }
    case 122:
#line 1193 "gram.y"
        {
/*
 *     VAR VALUE
 */

            if (!fatal)
            {
                vval();
                if (c_flag)
                {
                    c_put(yysave);
                }
            }
            ;
            break;
        }
    case 123:
#line 1207 "gram.y"
        {
/*
 *      ARRAY VALUE
 */

            if (!fatal)
            {
                aval();
                if (c_flag)
                {
                    c_put(yysave);
                    c_put("[");
                }
            }

            ;
            break;
        }
    case 124:
#line 1222 "gram.y"
        {
            if (!fatal)
            {
                ib_add(ADD);
                if (in_proc )
                    act_sp -= 1;
                ib_add(PUSH_);
                if (s_flag)
                {
                    as_inst_pr("add", "");
                    as_inst_pr("push*", "");
                }
                if (c_flag)
                {
                    c_put("]");
                }
            }
            ;
            break;
        }
    case 125:
#line 1241 "gram.y"
        {
/*
 *        VAR REFERENCE
 */
            if (!fatal)
            {
                vref();
                if (c_flag)
                {
                    c_put(yysave);
                }
            }
            ;
            break;
        }
    case 126:
#line 1254 "gram.y"
        {
/*
 *    ARRAY REFERENCE
 */
            if (!fatal)
            {
                aref();
                if (c_flag)
                {
                    c_put(yysave);
                }
            }

            ;
            break;
        }
    case 127:
#line 1267 "gram.y"
        {
            if (!fatal && c_flag)
            {
                c_put("[");
            }
            ;
            break;
        }
    case 128:
#line 1274 "gram.y"
        {
            if (!fatal)
            {
                ib_add(ADD);
                if (in_proc)
                    act_sp -= 1;
                if (s_flag)
                {
                    as_inst_pr("add", "");
                }
                if (c_flag)
                {
                    c_put("]");
                }
            }
            ;
            break;
        }
    }
    /* the action file gets copied in in place of this dollarsign */
#line 423 "/usr/local/lib/bison.simple"

    yyvsp -= yylen;
    yyssp -= yylen;
#ifdef YYLSP_NEEDED
    yylsp -= yylen;
#endif

#if YYDEBUG != 0
    if (yydebug)
    {
        short *ssp1 = yyss - 1;
        fprintf (stderr, "state stack now");
        while (ssp1 != yyssp)
            fprintf (stderr, " %d", *++ssp1);
        fprintf (stderr, "\n");
    }
#endif

    *++yyvsp = yyval;

#ifdef YYLSP_NEEDED
    yylsp++;
    if (yylen == 0)
    {
        yylsp->first_line = yylloc.first_line;
        yylsp->first_column = yylloc.first_column;
        yylsp->last_line = (yylsp-1)->last_line;
        yylsp->last_column = (yylsp-1)->last_column;
        yylsp->text = 0;
    }
    else
    {
        yylsp->last_line = (yylsp+yylen-1)->last_line;
        yylsp->last_column = (yylsp+yylen-1)->last_column;
    }
#endif

    /* Now "shift" the result of the reduction.
       Determine what state that goes to,
       based on the state we popped back to
       and the rule number reduced by.  */

    yyn = yyr1[yyn];

    yystate = yypgoto[yyn - YYNTBASE] + *yyssp;
    if (yystate >= 0 && yystate <= YYLAST && yycheck[yystate] == *yyssp)
        yystate = yytable[yystate];
    else
        yystate = yydefgoto[yyn - YYNTBASE];

    goto yynewstate;

yyerrlab:   /* here on detecting error */

    if (!yyerrstatus)
    /* If not already recovering from an error, report this error.  */
    {
        ++yynerrs;

#ifdef YYERROR_VERBOSE
        yyn = yypact[yystate];

        if (yyn > YYFLAG && yyn < YYLAST)
        {
            int size = 0;
            char *msg;
            int x, count;

            count = 0;
            for (x = 0; x < (sizeof(yytname) / sizeof(char *)); x++)
                if (yycheck[x + yyn] == x)
                    size += strlen(yytname[x]) + 15, count++;
            msg = (char *) xmalloc(size + 15);
            strcpy(msg, "parse error");

            if (count < 5)
            {
                count = 0;
                for (x = 0; x < (sizeof(yytname) / sizeof(char *)); x++)
                    if (yycheck[x + yyn] == x)
                    {
                        strcat(msg, count == 0 ? ", expecting `" : " or `");
                        strcat(msg, yytname[x]);
                        strcat(msg, "'");
                        count++;
                    }
            }
            yyerror(msg);
            free(msg);
        }
        else
#endif /* YYERROR_VERBOSE */
        yyerror("parse error");
    }

yyerrlab1:   /* here on error raised explicitly by an action */

    if (yyerrstatus == 3)
    {
        /* if just tried and failed to reuse lookahead token after an error, discard it.  */

        /* return failure if at end of input */
        if (yychar == YYEOF)
            YYABORT;

#if YYDEBUG != 0
        if (yydebug)
            fprintf(stderr, "Discarding token %d (%s).\n", yychar, yytname[yychar1]);
#endif

        yychar = YYEMPTY;
    }

    /* Else will try to reuse lookahead token
       after shifting the error token.  */

    yyerrstatus = 3;    /* Each real token shifted decrements this */

    goto yyerrhandle;

yyerrdefault:  /* current state does not do anything special for the error token. */

#if 0
    /* This is wrong; only states that explicitly want error tokens
       should shift them.  */
    yyn = yydefact[yystate]; /* If its default is to accept any token, ok.  Otherwise pop it.*/
    if (yyn)
        goto yydefault;
#endif

yyerrpop:   /* pop the current state because it cannot handle the error token */

    if (yyssp == yyss)
        YYABORT;
    yyvsp--;
    yystate = *--yyssp;
#ifdef YYLSP_NEEDED
    yylsp--;
#endif

#if YYDEBUG != 0
    if (yydebug)
    {
        short *ssp1 = yyss - 1;
        fprintf (stderr, "Error: state stack now");
        while (ssp1 != yyssp)
            fprintf (stderr, " %d", *++ssp1);
        fprintf (stderr, "\n");
    }
#endif

yyerrhandle:

    yyn = yypact[yystate];
    if (yyn == YYFLAG)
        goto yyerrdefault;

    yyn += YYTERROR;
    if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != YYTERROR)
        goto yyerrdefault;

    yyn = yytable[yyn];
    if (yyn < 0)
    {
        if (yyn == YYFLAG)
            goto yyerrpop;
        yyn = -yyn;
        goto yyreduce;
    }
    else if (yyn == 0)
        goto yyerrpop;

    if (yyn == YYFINAL)
        YYACCEPT;

#if YYDEBUG != 0
    if (yydebug)
        fprintf(stderr, "Shifting error token, ");
#endif

    *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
    *++yylsp = yylloc;
#endif

    yystate = yyn;
    goto yynewstate;
}
#line 1288 "gram.y"
/* end of rules section */
