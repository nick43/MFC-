/**************************************************************************
*                                                                         *
* ImageStruct.h -- GDI �������ͼƬ��ʽ�Ľṹ                             *
*                                                                         *
**************************************************************************/





#ifndef _IMAGESTRUCT_
#define _IMAGESTRUCT_

typedef unsigned int	UINT;

/*******************************************************/
/* BMPλͼ�ļ�����4����:                               */
/*    λͼ�ļ�ͷ�ṹBITMAPFILEHEADER                   */
/*	  λͼ��Ϣͷ�ṹBITMAPINFOHEADER                   */
/*	  λͼ��ɫ��RGBQUAD                                */
/*    λͼ��������                                     */
/*******************************************************/
//14byte BMP�ļ�ͷ����BMP�ļ������͡���С��λͼ�ļ��ı����֡�λͼ���ݾ��ļ�ͷ��ƫ����

//�Զ����������2�ֽ� ����View.h������ϵͳ�Դ���BMP�ṹ 
//ȫ�ֱ����ļ�ͷ BITMAPFILEHEADER bfh;
//ȫ�ֱ�����Ϣͷ BITMAPINFOHEADER bih;         

typedef struct T_BITMAPFILEHEADER {
	WORD       bfType;           //2byte λͼ�ļ������ͣ�����ΪBM 0x424d       
	DWORD      bfSize;           //4byte λͼ�ļ��Ĵ�С�����ֽ�Ϊ��λ    
	WORD       bfReserved1;      //2byte λͼ�ļ������֣�����Ϊ0         
	WORD       bfReserved2;      //2byte λͼ�ļ������֣�����Ϊ0         
    DWORD      bfOffBits;        //4byte λͼ���ݾ��ļ�ͷ��ƫ���������ֽ�Ϊ��λ
} BITMAPFILEHEADER_;

//�����BITMAPFILEHEADER_ ���ܶ����BITMAPFILEHEADER��MFC���Ѵ��ڻ��ظ�����

//40byte BMPλͼ��Ϣͷ����˵��λͼ�ĳߴ����Ϣ
typedef struct T_BITMAPINFOHEADER {
	DWORD      biSize;            //���ṹ��ռ���ֽ���
	LONG       biWidth;           //λͼ�Ŀ�ȣ�������Ϊ��λ
	LONG       biHeight;          //λͼ�ĸ߶ȣ�������Ϊ��λ
	WORD       biPlanes;          //Ŀ���豸�ļ��𣬱���Ϊ1
	WORD       biBitCount;        //ÿ�����������λ����������1��˫ɫ����
	                              //4��16ɫ����8��256ɫ����24�����ɫ��֮һ
	DWORD      biCompression;     //λͼѹ�����ͣ������� 0����ѹ������
	                              //1��BI_RLE8ѹ�����ͣ���2��BI_RLEѹ�����ͣ�֮һ
	DWORD      biSizeImage;       //λͼ�Ĵ�С�����ֽ�Ϊ��λ
	LONG       biXPelsPerMeter;   //λͼˮƽ�ֱ��ʣ�ÿ��������
	LONG       biYPelsPerMeter;   //λͼ��ֱ�ֱ��ʣ�ÿ��������
	DWORD      biClrUsed;         //λͼʵ��ʹ�õ���ɫ���е���ɫ��
	DWORD      biClrImportant;    //λͼ��ʾ��������Ҫ����ɫ�� 
} BITMAPINFOHEADER_;

//BMPλͼ��ɫ��
typedef struct T_RGBQUAD
{
    BYTE       rgbBlue;		      //��ɫ�����ȣ�ֵ��ΧΪ0��255��
    BYTE       rgbGreen;		  //��ɫ�����ȣ�ֵ��ΧΪ0��255��
    BYTE       rgbRed;			  //��ɫ�����ȣ�ֵ��ΧΪ0��255��
    BYTE       rgbReserved;	      //����������Ϊ0
} RGBQUAD_;

//ͼƬ��ʱ�洢��Ϣ��ȫ�ֱ���
	
#endif


