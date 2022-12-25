//#undef UNICODE
//#undef _UNICODE
#include<stdio.h>
#include<easyx.h>
#include"map_function.h"
#define WIDTH 640
#define HEIGHT 480
#define NUM_evt 10
#define DIAWIDTH 10
#define DIAHEIGHT 10


/**
 * @brief 图宝石链表节点(各难度设置一个文件)
 */
struct diamond
{
    int type;   //1->蓝宝石, 2->红宝石, 3->绿宝石
    float x;   //宝石的横坐标
    float y;   //宝石的纵坐标
    int n;  //宝石编号,便于修改删除
    struct diamond *next;
};

struct diamond *head = NULL;
struct diamond *end = NULL;

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

//=====================================================================================
//=====================================================================================
//=====================================================================================

void test()
{
    initgraph(WIDTH,HEIGHT);
    BeginBatchDraw();

    set_map(1);

    FlushBatchDraw();
}

int main (void)
{
    test();
    return 0;
}

void set_map(int dif)
{
    IMAGE map;
    switch(dif)
    {
        case 1: 
            loadimage(&map,_T("./image/lowlevel_map.png"),WIDTH,HEIGHT);
            break;
        case 2:
            loadimage(&map,_T("./image/hightlevel_map.png"),WIDTH,HEIGHT);
            break;
    }
    putimage(0,0,&map);
}

//================================================================================

void init_diamondlist()
{
    head = (struct diamond *)malloc(sizeof(struct diamond));
    head->next = NULL;
    end = head;
}

void load_diamond(int  dif)
{
    init_diamondlist();
    struct diamond *ptr = (struct diamond *)malloc(sizeof(struct diamond));
    ptr->next = NULL;

    FILE *fp = NULL;
    switch(dif)
    {
        case 1:
            fp = fopen("./data/lowlevel_diamond.txt","a+");
            break;
        case 2:
            fp = fopen("./data/hightlevel_diamond.txt","a+");
            break;
    }
    while(fscanf(fp,"%d %f %f %d\n",&ptr->type,&ptr->x,&ptr->y,&ptr->n))
    {
        if(head->next = NULL)
        {
            head->next = ptr;
        }
        else
        {
            end->next = ptr;
            end = end->next;
        }
        ptr = (struct diamond*)malloc(sizeof(struct diamond));
        ptr ->next = NULL;
    }
    free(ptr);
    fclose(fp);
}

void del_diamond(int n)
{
    struct diamond *pre = head;
    while(20030417)
    {
        if (pre->next&&(pre->next->n == n))
        {
            struct diamond *q = pre->next;
            pre->next = pre->next->next;
            free(q);
            return;
        }
        else
        {
            if(pre->next != NULL)
                pre = pre->next;
            else
                return;
        }
    }
}

void set_diamond(int dif,int n)
{
    struct diamond *p = head->next;
    while(p!=NULL)
    {
        IMAGE diamage;
        int n = p-> n;

        switch(p->type)
        {
            case 1:
                loadimage(&diamage, _T("./image/bluediamond.png"),DIAWIDTH,DIAHEIGHT); 
                break;
            case 2: 
                loadimage(&diamage, _T("./image/raddiamond.png"),DIAWIDTH,DIAHEIGHT); 
                break;
            case 3: 
                loadimage(&diamage, _T("./image/greendiamond.png"),DIAWIDTH,DIAHEIGHT); 
                break;
            break;
        }
        putimage(p->x,p->y,&diamage);

        p = p->next;
    }
}