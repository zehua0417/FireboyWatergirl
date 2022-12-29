#ifndef _MAP_FUNC
#define _MAP_FUNC

/**
 * @brief �����Ѷ�ѡ��, ��ӡ��ͼ
 * @param dif �Ѷ�,��select_dif()����
 */
void set_map(int dif);

void init_diamondlist();
void free_diamond();

/**
 * @brief ���ļ����뱦ʯ��Ϣ,��������
 * @param dif nandu,��select_dif()����
 */
void load_diamond(int  dif);

/**
 * @brief ��������ɾ��n�ű�ʯ
 * @param dif �Ѷ�
 * @param n Ҫɾ���ı�ʯ���
 */
struct diamond* del_diamond(int n);

/**
 * @brief ���ݺ���������ұ�ʯ
 * @param x ������
 * @param y ������
 *
 * @return 1, 2 ,... ��ʯ���
 *         0, δ�ҵ�
*/
void search_diamond(double fx, double fy, double wx, double wy);

/**
 * @brief ��ӡ��ʯ
 * @param head ��ʯ�����ͷ
 */
void set_diamond();

void init_diamond();

/**
 * @breif ���ļ����������Ϣ
 * @param dif �Ѷ�
 *
 * @return ���ݽṹ�������׵�ַ
 */
void load_evt(int dif);

/**
 * @brief ��ӡ����
 */
void set_evt();



void press_button(double fx, double fy, double wx, double wy);
/**
 * @brief ���ļ����밴ť��Ϣ
 * @param dif �Ѷ�
 *
 * @return ��ť�ṹ��������Ŷ��ַ
 */
void load_button(int dif);

/**
 * @brief ��ӡ��ť
 */
void set_button();
void transparentimage(IMAGE* dstimg, int x, int y, IMAGE* srcimg);


#endif
