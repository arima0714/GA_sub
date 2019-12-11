void init();
int return_rand(int num);
void calc_fitness(void);
void xselect(void);
void index_sort(void);
void swap_content(int a, int b);
void crossing();
void calc_fitness_test(void);
void crossing_test(void);
void xselect_test(void);
void index_sort_test(void);
void swap_content_test(void);
void test(void);
int get_index(int num);
void get_index_test();


void init_indexes(int NOG, int NOC, int index[NOG][NOC], int root_array[NOC]);
void input_root_array(int NOC, int root_array[NOC]);
void init_mutate(int NOG, int NOC, int index[NOG][NOC]);
