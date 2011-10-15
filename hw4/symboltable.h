#ifndef SYMBOL_TABLE
#define SYMBOL_TABLE

/*struct c_type {
  int base_type;    // 1 = int, 2=float, ... 
  union {
    struct array {
      int size;
      struct c_type *elemtype;
    } a;
    struct ctype *p;
    struct struc {
      char *label;
      struct field **f;
    } s;
  } u;
}
*/ 

typedef struct field {
  char *name;
  int type;
  //struct ctype *elemtype;
} field;
  
typedef struct symbol_table { 
  struct symbol_table* parent;
  int nSymbols;
  field fields[50];
} symbol_table;

symbol_table* makeTable(symbol_table* parent);

int findIdentLocally(symbol_table* table, char* ident); //no recursion up
int findIdent(symbol_table* table, char* ident); //searches up
int addSymbol(symbol_table* table, char* ident, int type);

#endif
