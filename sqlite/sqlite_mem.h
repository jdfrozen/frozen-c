typedef enum { PREPARE_SUCCESS, PREPARE_UNRECOGNIZED_STATEMENT } PrepareResult;
typedef enum { STATEMENT_INSERT, STATEMENT_SELECT } StatementType;
typedef enum { EXECUTE_SUCCESS, EXECUTE_TABLE_FULL } ExecuteResult;
//行定义
#define COLUMN_USERNAME_SIZE 32
#define COLUMN_EMAIL_SIZE 255
typedef struct {
  uint32_t id;
  char username[COLUMN_USERNAME_SIZE + 1];
  char email[COLUMN_EMAIL_SIZE + 1];
}Row;
//数据库状态
typedef struct {
  StatementType type;
  Row row_to_insert;
} Statement;

//行与地址存储转换
#define size_of_attribute(Struct, Attribute) sizeof(((Struct*)0)->Attribute)
#define size_add(x, y) (x+y)

#define TABLE_MAX_PAGES 100
typedef struct {
  uint32_t num_rows;
  void* pages[TABLE_MAX_PAGES];
} Table;

ExecuteResult execute_statement(Statement* statement,Table* table);
//insert
ExecuteResult execute_insert(Statement* statement, Table* table);
//select
ExecuteResult execute_select(Statement* statement, Table* table);
Table* new_table();
void free_table(Table* table);
