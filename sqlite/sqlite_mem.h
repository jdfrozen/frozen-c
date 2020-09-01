//行定义
#define COLUMN_USERNAME_SIZE 32
#define COLUMN_EMAIL_SIZE 255
#define TABLE_MAX_PAGES 100
//获取结构体属性内存
#define size_of_attribute(Struct, Attribute) sizeof(((Struct*)0)->Attribute)

typedef enum { PREPARE_SUCCESS, PREPARE_UNRECOGNIZED_STATEMENT } PrepareResult;
typedef enum { STATEMENT_INSERT, STATEMENT_SELECT } StatementType;
typedef enum { EXECUTE_SUCCESS, EXECUTE_TABLE_FULL } ExecuteResult;
typedef enum { NODE_INTERNAL, NODE_LEAF } NodeType;

typedef struct {
  uint32_t id;
  char username[COLUMN_USERNAME_SIZE + 1];
  char email[COLUMN_EMAIL_SIZE + 1];
}Row;
//数据库状态
typedef struct {
  StatementType type;
  Row row_to_insert;
}Statement;
//页定义
typedef struct {
  int file_descriptor;
  uint32_t file_length;
  uint32_t num_pages;
  void* pages[TABLE_MAX_PAGES];
} Pager;
//表定义
typedef struct {
  void* pages[TABLE_MAX_PAGES];
  Pager* pager;
  uint32_t root_page_num;
} Table;
//游标定义
typedef struct {
  Table* table;
  uint32_t page_num;
  uint32_t cell_num;
  bool end_of_table;  // Indicates a position one past the last element
} Cursor;

ExecuteResult execute_statement(Statement* statement,Table* table);
//insert
ExecuteResult execute_insert(Statement* statement, Table* table);
//select
ExecuteResult execute_select(Statement* statement, Table* table);
//打开表
Table* db_open(const char* filename);
//关闭表
void db_close(Table* table);
void* get_page(Pager* pager, uint32_t page_num);
void print_leaf_node(void* node);
void print_constants();
