#include <stdio.h>
#include <windows.h>
#include <process.h> 

int end = 0;
void calc()//原程序作为子线程开始
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
//原程序作为子线程结束
//长时间计算子程序

void MyThread(void*)
{
    calc();
    _endthread();//结束线程
}//线程主体

int main()
{
    printf("欢迎使用热爱客软件——热爱客键盘模拟鼠标点击\n使用方法：F9:左键，F10：右键，F11退出\n本程序开源，github：https://github.com/qjhelecfan/reak\n程序下载地址：www.reak.ml/ryktools\n如需技术支持，请于热爱客首页(reak.ml)联系站长\n");  
    int n;
    HANDLE hThread = (HANDLE)_beginthread(MyThread, 0, NULL);//创建另一线程
    for(n=0;!end;++n)
    {
        //idle time = 90%, busy time = 10%
        if(n==10) n=0;
        if(n==0) SuspendThread(hThread);//挂起线程
        if(n==9) ResumeThread(hThread);//恢复线程  
        Sleep(3);
        if(GetAsyncKeyState(VK_F11))
		{
            printf("QUIT\n");
			break;
		}
    }
    printf("OK!\n");
    return 0;
}//主线程
