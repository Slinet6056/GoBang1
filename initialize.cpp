#include "initialize.h"

void initialize() {
    while (!record.empty()) record.pop();
    memset(board, 0, sizeof(board));
    firstPlayer = 1;
    secondPlayer = 1;
    setbkcolor(BKCOLOR);
    cleardevice();
    LOGFONT f;
    RECT r;
    //棋盘线
    setlinecolor(BLACK);
    setlinestyle(PS_SOLID, 1);
    for (int i = 75; i <= 675; i += 50) {
        line(i, 25, i, 725);
        line(25, i, 725, i);
    }
    setlinestyle(PS_SOLID, 3);
    line(25, 25, 25, 725);
    line(725, 25, 725, 725);
    line(25, 25, 725, 25);
    line(25, 725, 725, 725);
    //棋盘点
    setfillcolor(BLACK);
    solidcircle(375, 375, 3);
    solidcircle(175, 175, 3);
    solidcircle(175, 575, 3);
    solidcircle(575, 175, 3);
    solidcircle(575, 575, 3);
    //先手-提示文字
    gettextstyle(&f);
    f.lfHeight = 30;
    f.lfQuality = ANTIALIASED_QUALITY;
    _tcscpy_s(f.lfFaceName, _T("微软雅黑"));
    settextstyle(&f);
    settextcolor(myBLACK);
    setbkcolor(BKCOLOR);
    outtextxy(760, 20, _T("先手-黑子:"));
    //先手-选择1
    setfillcolor(myBLACK);
    solidroundrect(760, 60, 930, 120, 25, 25);
    gettextstyle(&f);
    f.lfHeight = 35;
    f.lfQuality = ANTIALIASED_QUALITY;
    _tcscpy_s(f.lfFaceName, _T("微软雅黑"));
    settextstyle(&f);
    settextcolor(myWHITE);
    setbkcolor(myBLACK);
    r = {760, 60, 930, 120};
    drawtext(_T("玩  家"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    //先手-选择2
    setfillcolor(myWHITE);
    solidroundrect(760, 130, 930, 190, 25, 25);
    setlinecolor(myBLACK);
    setlinestyle(PS_SOLID, 3);
    setbkcolor(myWHITE);
    roundrect(761, 131, 929, 189, 25, 25);
    gettextstyle(&f);
    f.lfHeight = 35;
    f.lfQuality = ANTIALIASED_QUALITY;
    _tcscpy_s(f.lfFaceName, _T("微软雅黑"));
    settextstyle(&f);
    settextcolor(myBLACK);
    setbkcolor(myWHITE);
    r = {760, 130, 930, 190};
    drawtext(_T("A    I"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    //后手-提示文字
    gettextstyle(&f);
    f.lfHeight = 30;
    f.lfQuality = ANTIALIASED_QUALITY;
    _tcscpy_s(f.lfFaceName, _T("微软雅黑"));
    settextstyle(&f);
    settextcolor(myBLACK);
    setbkcolor(BKCOLOR);
    outtextxy(760, 210, _T("后手-白子:"));
    //后手-选择1
    setfillcolor(myBLACK);
    solidroundrect(760, 250, 930, 310, 25, 25);
    gettextstyle(&f);
    f.lfHeight = 35;
    f.lfQuality = ANTIALIASED_QUALITY;
    _tcscpy_s(f.lfFaceName, _T("微软雅黑"));
    settextstyle(&f);
    settextcolor(myWHITE);
    setbkcolor(myBLACK);
    r = {760, 250, 930, 310};
    drawtext(_T("玩  家"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    //后手-选择2
    setfillcolor(myWHITE);
    solidroundrect(760, 320, 930, 380, 25, 25);
    setlinecolor(myBLACK);
    setlinestyle(PS_SOLID, 3);
    setbkcolor(myWHITE);
    roundrect(761, 321, 929, 379, 25, 25);
    gettextstyle(&f);
    f.lfHeight = 35;
    f.lfQuality = ANTIALIASED_QUALITY;
    _tcscpy_s(f.lfFaceName, _T("微软雅黑"));
    settextstyle(&f);
    settextcolor(myBLACK);
    setbkcolor(myWHITE);
    r = {760, 320, 930, 380};
    drawtext(_T("A    I"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    //开始按钮
    setfillcolor(myWHITE);
    solidroundrect(760, 420, 930, 480, 25, 25);
    setlinecolor(myBLACK);
    setlinestyle(PS_SOLID, 3);
    setbkcolor(myWHITE);
    roundrect(761, 421, 929, 479, 24, 24);
    roundrect(767, 427, 923, 473, 18, 18);
    gettextstyle(&f);
    f.lfHeight = 35;
    f.lfQuality = ANTIALIASED_QUALITY;
    _tcscpy_s(f.lfFaceName, _T("微软雅黑"));
    settextstyle(&f);
    settextcolor(myBLACK);
    setbkcolor(myWHITE);
    r = {760, 420, 930, 480};
    drawtext(_T("开  始"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    //退出
    setfillcolor(myBLACK);
    solidroundrect(760, 660, 930, 720, 25, 25);
    setlinecolor(myWHITE);
    setlinestyle(PS_SOLID, 3);
    setbkcolor(myBLACK);
    roundrect(764, 664, 926, 716, 20, 20);
    gettextstyle(&f);
    f.lfHeight = 35;
    f.lfQuality = ANTIALIASED_QUALITY;
    _tcscpy_s(f.lfFaceName, _T("微软雅黑"));
    settextstyle(&f);
    settextcolor(myWHITE);
    setbkcolor(myBLACK);
    r = {760, 660, 930, 720};
    drawtext(_T("退  出"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    //鼠标操作
    MOUSEMSG m; // NOLINT(cppcoreguidelines-pro-type-member-init)
    int temp = 0;
    while (true) {
        m = GetMouseMsg();
        switch (m.uMsg) {
            case WM_LBUTTONDOWN:
                if (m.x > 760 && m.x < 930 && m.y > 60 && m.y < 120) { //先手-玩家
                    firstPlayer = 1;
                    setfillcolor(myBLACK);
                    solidroundrect(760, 60, 930, 120, 25, 25);
                    gettextstyle(&f);
                    f.lfHeight = 35;
                    f.lfQuality = ANTIALIASED_QUALITY;
                    _tcscpy_s(f.lfFaceName, _T("微软雅黑"));
                    settextstyle(&f);
                    settextcolor(myWHITE);
                    setbkcolor(myBLACK);
                    r = {760, 60, 930, 120};
                    drawtext(_T("玩  家"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
                    setfillcolor(myWHITE);
                    solidroundrect(760, 130, 930, 190, 25, 25);
                    setlinecolor(myBLACK);
                    setlinestyle(PS_SOLID, 3);
                    setbkcolor(myWHITE);
                    roundrect(761, 131, 929, 189, 25, 25);
                    gettextstyle(&f);
                    f.lfHeight = 35;
                    f.lfQuality = ANTIALIASED_QUALITY;
                    _tcscpy_s(f.lfFaceName, _T("微软雅黑"));
                    settextstyle(&f);
                    settextcolor(myBLACK);
                    setbkcolor(myWHITE);
                    r = {760, 130, 930, 190};
                    drawtext(_T("A    I"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
                } else if (m.x > 760 && m.x < 930 && m.y > 130 && m.y < 190) { //先手-AI
                    firstPlayer = 2;
                    setfillcolor(myWHITE);
                    solidroundrect(760, 60, 930, 120, 25, 25);
                    setlinecolor(myBLACK);
                    setlinestyle(PS_SOLID, 3);
                    setbkcolor(myWHITE);
                    roundrect(761, 61, 929, 119, 25, 25);
                    gettextstyle(&f);
                    f.lfHeight = 35;
                    f.lfQuality = ANTIALIASED_QUALITY;
                    _tcscpy_s(f.lfFaceName, _T("微软雅黑"));
                    settextstyle(&f);
                    settextcolor(myBLACK);
                    setbkcolor(myWHITE);
                    r = {760, 60, 930, 120};
                    drawtext(_T("玩  家"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
                    setfillcolor(myBLACK);
                    solidroundrect(760, 130, 930, 190, 25, 25);
                    gettextstyle(&f);
                    f.lfHeight = 35;
                    f.lfQuality = ANTIALIASED_QUALITY;
                    _tcscpy_s(f.lfFaceName, _T("微软雅黑"));
                    settextstyle(&f);
                    settextcolor(myWHITE);
                    setbkcolor(myBLACK);
                    r = {760, 130, 930, 190};
                    drawtext(_T("A    I"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
                } else if (m.x > 760 && m.x < 930 && m.y > 250 && m.y < 310) { //后手-玩家
                    secondPlayer = 1;
                    setfillcolor(myBLACK);
                    solidroundrect(760, 250, 930, 310, 25, 25);
                    gettextstyle(&f);
                    f.lfHeight = 35;
                    f.lfQuality = ANTIALIASED_QUALITY;
                    _tcscpy_s(f.lfFaceName, _T("微软雅黑"));
                    settextstyle(&f);
                    settextcolor(myWHITE);
                    setbkcolor(myBLACK);
                    r = {760, 250, 930, 310};
                    drawtext(_T("玩  家"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
                    setfillcolor(myWHITE);
                    solidroundrect(760, 320, 930, 380, 25, 25);
                    setlinecolor(myBLACK);
                    setlinestyle(PS_SOLID, 3);
                    setbkcolor(myWHITE);
                    roundrect(761, 321, 929, 379, 25, 25);
                    gettextstyle(&f);
                    f.lfHeight = 35;
                    f.lfQuality = ANTIALIASED_QUALITY;
                    _tcscpy_s(f.lfFaceName, _T("微软雅黑"));
                    settextstyle(&f);
                    settextcolor(myBLACK);
                    setbkcolor(myWHITE);
                    r = {760, 320, 930, 380};
                    drawtext(_T("A    I"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
                } else if (m.x > 760 && m.x < 930 && m.y > 320 && m.y < 380) { //后手-AI
                    secondPlayer = 2;
                    setfillcolor(myWHITE);
                    solidroundrect(760, 250, 930, 310, 25, 25);
                    setlinecolor(myBLACK);
                    setlinestyle(PS_SOLID, 3);
                    setbkcolor(myWHITE);
                    roundrect(761, 251, 929, 309, 25, 25);
                    gettextstyle(&f);
                    f.lfHeight = 35;
                    f.lfQuality = ANTIALIASED_QUALITY;
                    _tcscpy_s(f.lfFaceName, _T("微软雅黑"));
                    settextstyle(&f);
                    settextcolor(myBLACK);
                    setbkcolor(myWHITE);
                    r = {760, 250, 930, 310};
                    drawtext(_T("玩  家"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
                    setfillcolor(myBLACK);
                    solidroundrect(760, 320, 930, 380, 25, 25);
                    gettextstyle(&f);
                    f.lfHeight = 35;
                    f.lfQuality = ANTIALIASED_QUALITY;
                    _tcscpy_s(f.lfFaceName, _T("微软雅黑"));
                    settextstyle(&f);
                    settextcolor(myWHITE);
                    setbkcolor(myBLACK);
                    r = {760, 320, 930, 380};
                    drawtext(_T("A    I"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
                } else if (m.x > 760 && m.x < 930 && m.y > 420 && m.y < 480) { //按下开始按钮
                    setfillcolor(myBLACK);
                    solidroundrect(760, 420, 930, 480, 25, 25);
                    setlinecolor(myWHITE);
                    setlinestyle(PS_SOLID, 3);
                    setbkcolor(myBLACK);
                    roundrect(764, 424, 926, 476, 20, 20);
                    gettextstyle(&f);
                    f.lfHeight = 35;
                    f.lfQuality = ANTIALIASED_QUALITY;
                    _tcscpy_s(f.lfFaceName, _T("微软雅黑"));
                    settextstyle(&f);
                    settextcolor(myWHITE);
                    setbkcolor(myBLACK);
                    r = {760, 420, 930, 480};
                    drawtext(_T("开  始"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
                    temp = 1;
                } else if (m.x > 760 && m.x < 930 && m.y > 650 && m.y < 710) { //退出
                    exit(0);
                }
                break;
            case WM_LBUTTONUP:
                if (m.x > 760 && m.x < 930 && m.y > 420 && m.y < 480 && temp == 1) { //开始
                    //重新开始
                    setfillcolor(myWHITE);
                    solidroundrect(760, 420, 930, 480, 25, 25);
                    setlinecolor(myBLACK);
                    setlinestyle(PS_SOLID, 3);
                    setbkcolor(myWHITE);
                    roundrect(761, 421, 929, 479, 24, 24);
                    roundrect(767, 427, 923, 473, 18, 18);
                    gettextstyle(&f);
                    f.lfHeight = 35;
                    f.lfQuality = ANTIALIASED_QUALITY;
                    _tcscpy_s(f.lfFaceName, _T("微软雅黑"));
                    settextstyle(&f);
                    settextcolor(myBLACK);
                    setbkcolor(myWHITE);
                    r = {760, 420, 930, 480};
                    drawtext(_T("重新开始"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
                    //悔棋
                    setfillcolor(myWHITE);
                    solidroundrect(760, 490, 930, 550, 25, 25);
                    setlinecolor(myBLACK);
                    setlinestyle(PS_SOLID, 3);
                    setbkcolor(myWHITE);
                    roundrect(761, 491, 929, 549, 24, 24);
                    roundrect(767, 497, 923, 543, 18, 18);
                    gettextstyle(&f);
                    f.lfHeight = 35;
                    f.lfQuality = ANTIALIASED_QUALITY;
                    _tcscpy_s(f.lfFaceName, _T("微软雅黑"));
                    settextstyle(&f);
                    settextcolor(myBLACK);
                    setbkcolor(myWHITE);
                    r = {760, 490, 930, 550};
                    drawtext(_T("悔  棋"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
                    //提示
                    setfillcolor(myWHITE);
                    solidroundrect(760, 560, 930, 620, 25, 25);
                    setlinecolor(myBLACK);
                    setlinestyle(PS_SOLID, 3);
                    setbkcolor(myWHITE);
                    roundrect(761, 561, 929, 619, 24, 24);
                    roundrect(767, 567, 923, 613, 18, 18);
                    gettextstyle(&f);
                    f.lfHeight = 35;
                    f.lfQuality = ANTIALIASED_QUALITY;
                    _tcscpy_s(f.lfFaceName, _T("微软雅黑"));
                    settextstyle(&f);
                    settextcolor(myBLACK);
                    setbkcolor(myWHITE);
                    r = {760, 560, 930, 620};
                    drawtext(_T("提  示"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
                    return;
                } else {
                    setfillcolor(myWHITE);
                    solidroundrect(760, 420, 930, 480, 25, 25);
                    setlinecolor(myBLACK);
                    setlinestyle(PS_SOLID, 3);
                    setbkcolor(myWHITE);
                    roundrect(761, 421, 929, 479, 24, 24);
                    roundrect(767, 427, 923, 473, 18, 18);
                    gettextstyle(&f);
                    f.lfHeight = 35;
                    f.lfQuality = ANTIALIASED_QUALITY;
                    _tcscpy_s(f.lfFaceName, _T("微软雅黑"));
                    settextstyle(&f);
                    settextcolor(myBLACK);
                    setbkcolor(myWHITE);
                    r = {760, 420, 930, 480};
                    drawtext(_T("开  始"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
                    temp = 0;
                }
        }
    }
}