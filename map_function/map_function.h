#ifndef _MAP_FUNC
#define _MAP_FUNC

/**
 * @brief 根据难度选择, 打印地图
 * @param dif 难度,见select_dif()函数
 */
void set_map(int dif);

void init_diamondlist();

/**
 * @brief 从文件读入宝石信息,生成链表
 * @param dif nandu,见select_dif()函数
 */
void load_diamond(int  dif);

/**
 * @brief 从链表中删除n号宝石
 * @param dif 难度
 * @param n 要删除的宝石编号
 */
void del_diamond(int dif, int n);

/**
 * @brief 打印宝石
 * @param head 宝石链表表头
 */
void set_diamond(struct diamond *head);

/**
 * @breif 从文件读入电梯信息
 * @param dif 难度
 * 
 * @return 电梯结构体数组首地址
 */
struct evt *laod_evt(int dif);

/**
 * @brief 打印电梯
 * @param evt_head 电梯结构体数组首地址
 */
void set_evt(struct evt *evt_head);

/**
 * @brief 从文件读入按钮信息
 * @param dif 难度
 * 
 * @return 按钮结构体数组收哦地址
 */
struct button *load_button(int dif);

/**
 * @brief 打印按钮
 * @param button_head 按钮结构体数组首地址
 */
void set_button(struct button *button_head);

#endif