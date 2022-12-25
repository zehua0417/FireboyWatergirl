/**
 * @file 森林冰火人项目架构
 * @author: lihuax
 * @version: 1.0
 */
#include<graphics.h>

//=================================================常量=================================================================
/*人物速度V_hero; 电梯加速度V_evt; 加速度A; 重力加速图G; 帧率P; 电梯最大数量NUM_evt; */
#define NUM_evt 10

//==================================================结构体=================================================================
/**
 * @brief 图宝石链表节点(各难度设置一个文件)
 */
struct diamond
{
    int type;   //1->蓝宝石, 2->红宝石, 3->绿宝石
    double x;   //宝石的横坐标
    double y;   //宝石的纵坐标
    int n;  //宝石编号,便于修改删除
    struct map *next;
};

/**
 * @brief 地板或天花板模型结构体(来自CSDN)
 */
typedef struct model1
{
	int x1 = 0, x2 = 1100, y1 = 699, y2 = 714;//714
}model1_;

model1_ floor[10][100], roof[10][100];//模型结构体数组(每个地图一个)

/**
 * @brief 左右墙壁模型结构体(来自CSDN)
 */
typedef struct model2
{
	int x = 369, y1 = 617, y2 = 621;
}model2_;

model2_ wallleft[10][100], wallright[10][100];//模型结构体数组(每个地图一个)

/**
 * @brief 电梯结构体
*/
struct evt
{
    int x;  //横坐标
    int y;  //纵坐标
    int n;  //电梯编号,便于和按钮对应
    int type;   //运动类型: 1,上->下; 2,下->上; 3,左->右; 4,右->左
    double distance;    //可以滑行的距离
    double dis_now;     //电梯此时的位置(相对起点的距离)<=distance
};

struct evt lowlevel_wvt[NUM_evt];    //设置电梯结构体数组, 每个关卡一个

/**
 * @brief 按钮结构体
*/
struct button
{
    int x;  //横坐标
    int y;  //纵坐标
    int n;  //编号
    double status;  //状态即被按下的深度
};

struct button lowlevel_button[NUM_evt];  //设置按钮结构体数组, 每个关卡一个

/**
 * @brief 陷阱结构体
*/
//struct river
//{
//    int x;  //横坐标
//    int y;  //纵坐标
//    int type;   //类型: 1.水; 2. 火; 3.绿水
//    double length;  //长度
//
//}
//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

struct fireboy
{
    IMAGE* head; 
};

struct watergirl
{

};


//==================================================第一部分: 开始菜单======================================================
/**
 * @brief 打印开始菜单, 并判断鼠标操作
 * 
 * @return 
 *      -<em> 1 </em> 开始游戏->选择难度
 *      -<em> 2 </em> 设置音量
 *      -<em> 3 </em> 查看玩法
 *      -<em> 4 </em> 查看开发者
 */
int init_startpage();

//====================================================第二部分: 难度选择==========================================================
/**
 * @brief 打印难度选择页面, 并判断鼠标操作
 * 
 * @return 
 *      -<em> 1 </em> 难度:容易
 *      -<em> 2 </em> 难度:中等
 */
int select_dif();

//========================================================第三部分: 打印地图===========================================================
/**
 * @brief 根据难度选择, 打印地图
 * @param dif 难度,见select_dif()函数
 */
void set_map(int dif);

void init_diamondlist();

/**
 * @brief 从文件读入宝石信息,生成链表
 * @param dif nandu,见select_dif()函数
 * 
 * @return struct diamond *head 宝石链表表头
 */
struct diamond *load_diamond(int  dif);

/**
 * @brief 从链表中删除n号宝石
 * @param n 要删除的宝石编号
 */
void del_diamond(int n);

/**
 * @brief 打印宝石
 */
void set_diamond();

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

//==============================================================第四部分: 人额移动==========================================================



//==============================================================第五部分: 判定==============================================================

//================================================================第六部分: 音量设置=========================================================
