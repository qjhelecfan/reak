#include <stdio.h>
#include <windows.h>
#include <process.h> 

int end = 0;
void calc()//ԭ������Ϊ���߳̿�ʼ
{
  system("title mouseclick V3.0");
	while(1)
	{
			
		if(GetAsyncKeyState(VK_F9)<0)
		{
			mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0);
			printf("LeftDown\n");
			while(GetAsyncKeyState(VK_F9)<0)  {}
            mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0);
	       	printf("LeftUp\n");
		}
		else
		{
			if(GetAsyncKeyState(VK_F10)<0)
	    	{
		    	mouse_event(MOUSEEVENTF_RIGHTDOWN,0,0,0,0);
                printf("RightDown\n");
	      		while(GetAsyncKeyState(VK_F10)<0)  {}
                mouse_event(MOUSEEVENTF_RIGHTUP,0,0,0,0);
	       	    printf("RightUp\n");
		    }
			else 
			{
				printf("");
			}
		}
	}
}
//ԭ������Ϊ���߳̽���
//��ʱ������ӳ���

void MyThread(void*)
{
    calc();
    _endthread();//�����߳�
}//�߳�����

int main()
{
    printf("��ӭʹ���Ȱ�����������Ȱ��ͼ���ģ�������\nʹ�÷�����F9:�����F10���Ҽ���F11�˳�\n������Դ��github��https://github.com/qjhelecfan/reak\n�������ص�ַ��www.reak.ml/ryktools\n���輼��֧�֣������Ȱ�����ҳ(reak.ml)��ϵվ��\n");  
    int n;
    HANDLE hThread = (HANDLE)_beginthread(MyThread, 0, NULL);//������һ�߳�
    for(n=0;!end;++n)
    {
        //idle time = 90%, busy time = 10%
        if(n==10) n=0;
        if(n==0) SuspendThread(hThread);//�����߳�
        if(n==9) ResumeThread(hThread);//�ָ��߳�  
        Sleep(3);
        if(GetAsyncKeyState(VK_F11))
		{
            printf("QUIT\n");
			break;
		}
    }
    printf("OK!\n");
    return 0;
}//���߳�
