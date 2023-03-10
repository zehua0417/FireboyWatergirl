#ifndef _MAP_FUNC
#define _MAP_FUNC

/**
 * @brief 根据难度选择, 打印地图
 * @param dif 难度,见select_dif()函数
 */
void set_map(int dif);

void init_diamondlist();
void free_diamond();

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
struct diamond* del_diamond(int n);

/**
 * @brief 根据横纵坐标查找宝石
 * @param x 横坐标
 * @param y 纵坐标
 *
 * @return 1, 2 ,... 宝石编号
 *         0, 未找到
*/
void search_diamond(double fx, double fy, double wx, double wy);

/**
 * @brief 打印宝石
 * @param head 宝石链表表头
 */
void set_diamond();

void init_diamond();

/**
 * @breif 从文件读入电梯信息
 * @param dif 难度
 *
 * @return 电梯结构体数组首地址
 */
void load_evt(int dif);

/**
 * @brief 打印电梯
 */
void set_evt();



void press_button(double fx, double fy, double wx, double wy);
/**
 * @brief 从文件读入按钮信息
 * @param dif 难度
 *
 * @return 按钮结构体数组收哦地址
 */
void load_button(int dif);

/**
 * @brief 打印按钮
 */
void set_button();
void transparentimage(IMAGE* dstimg, int x, int y, IMAGE* srcimg);


#endif
