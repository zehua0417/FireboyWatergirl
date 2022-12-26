#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<graphics.h>

#define WIDTH 640
#define HEIGHT 480
#define DIAWIDTH 110
#define DIAHEIGHT 106
#define EVTWIDTH 50
#define EVTHEIGHT 10
#define NUM_evt 10

/**
 * @brief 图宝石链表节点(各难度设置一个文件)
 */
struct gem
{
    int type; // 1->蓝宝石, 2->红宝石, 3->绿宝石
    float x;  // 宝石的横坐标
    float y;  // 宝石的纵坐标
    int n;    // 宝石编号,便于修改删除
    struct gem *next;
};

/**
 * @brief 电梯结构体
 */
struct evt
{
    int x;           // 横坐标
    int y;           // 纵坐标
    int n;           // 电梯编号,便于和按钮对应
    int type;        // 运动类型: 1,上->下; 2,下->上; 3,左->右; 4,右->左
    double distance; // 可以滑行的距离
    double dis_now;  // 电梯此时的位置(相对起点的距离)<=distance
};

struct evt evt_data[NUM_evt] = {0}; // 设置电梯结构体数组, 每个关卡一个

/**
 * @brief 按钮结构体
 */
struct button
{
    int x;         // 横坐标
    int y;         // 纵坐标
    int n;         // 编号
    double status; // 状态即被按下的深度
};

struct button button_data[NUM_evt] = {0}; // 设置按钮结构体数组, 每个关卡一个

struct gem *init_gem()
{
    struct gem *new_node = (struct gem *)malloc(sizeof(struct gem));
    new_node->next = NULL;
    return new_node;
}

void add_new_gem(struct gem **head, struct gem **new_node, int pos)
{
    struct gem *now;
    now = *head;
    if(pos<0)
    {
        pos = 0;
    }
    for (int i=1; i<pos;i++)
    {
        if(now->next)
        {
            now = now->next;
        }
        if(pos)
        {
            (*new_node)->next = now->next;
            now->next = *new_node;
        }
        else
        {
            (*new_node)->next = *head;
            *head = *new_node;
        }
    }
}

int search_gem(struct gem *head,double x, double y)
{
    struct gem *now;
    now = head;
    int yes = 0;
    while(now)
    {
        if(fabs(now->x-x)<=3&&fabs(now->y-y)<=3)
        {
            yes++;
        }
        now = now->next;
    }
    if(yes)
    {
        return now->n;
    }
    else 
        return 0;
}

struct gem *get_input()
{
    struct gem *now = init_gem();
    printf("input:\n");
    scanf("%1d %4.2f %4.2f %2d", &(now->type), &(now->x), &(now->y), &(now->n));
    getchar();
    return now;
}

void set_gem(struct gem *head)
{
    struct gem* p;
    p = head;
    while(p)
    {
        IMAGE gemimage;
        int n = p->n;

        switch (p->type)
        {
        case 1:
            loadimage(&gemimage, _T("./image/bluediamond.png"), DIAWIDTH, DIAHEIGHT);
            break;
        case 2:
            loadimage(&gemimage, _T("./image/raddiamond.png"), DIAWIDTH, DIAHEIGHT);
            break;
        case 3:
            loadimage(&gemimage, _T("./image/greendiamond.png"), DIAWIDTH, DIAHEIGHT);
            break;
        }
        putimage(p->x,p->y,&gemimage);

        p = p->next;
    }
}

int main (void)
{
    int pos = 0;
    struct gem *head;
    head=NULL;
    struct gem *now = get_input();
    if(head)
    {
        scanf("%d",&pos);
        add_new_gem(&head,&now,pos);
    }
}
