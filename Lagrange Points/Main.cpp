#include <Windows.h>
#include <tchar.h>
#include <cmath>
#include <ctime>

// The main window class name.
static TCHAR szWindowClass[] = _T("Lagrange Point Calculator");

// The string that appears in the application's title bar.
static TCHAR szTitle[] = _T("Lagrange Point Calculator");

// Stored instance handle for use in Win32 API calls such as FindResource.
HINSTANCE hInst;

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

//Turns out C++'s base vector library isn't for math vectors:
struct vector3 {
    float values[3] = { 0, 0, 0 };

    vector3(float tvalues[3]) {
        *values = *tvalues;

    }

    vector3() {
        //*values = {0, 0, 0};
        throw (values[0]);
    }
};

//Objects which behave via kepler's laws of planetary motion.
class keplerObject {
    //Keeping these to avoid recalculating them every frame. They are calculated in the calculateFrame function.
    vector3 position;
    vector3 velocity;

    void calculateFrame() {
        //Calculate the new position and velocity based on kepler's laws.
    }
};

//Objects which behave via Newton's law of universal gravity.
class gravityObject {
    vector3 position;
    vector3 velocity;

    //Update the position and velocity every frame
    void calculateFrame() {
        //position += velocity;
    }

    gravityObject() {

    };
};

int WINAPI WinMain(
    _In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPSTR     lpCmdLine,
    _In_ int       nCmdShow
) {
    // Some stuff for the window to work.
    WNDCLASSEX wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);
    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = WndProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = hInstance;
    wcex.hIcon = LoadIcon(wcex.hInstance, IDI_APPLICATION);
    wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wcex.lpszMenuName = NULL;
    wcex.lpszClassName = szWindowClass;
    wcex.hIconSm = LoadIcon(wcex.hInstance, IDI_APPLICATION);

    if (!RegisterClassEx(&wcex))
    {
        MessageBox(NULL,
            _T("Call to RegisterClassEx failed!"),
            _T("Windows Desktop Guided Tour"),
            NULL);

        return 1;
    }

    HWND hWnd = CreateWindowEx(
        WS_EX_OVERLAPPEDWINDOW,
        szWindowClass,
        szTitle,
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT,
        500, 100,
        NULL,
        NULL,
        hInstance,
        NULL
    );
    if (!hWnd)
    {
        MessageBox(NULL,
            _T("Call to CreateWindowEx failed!"),
            _T("Windows Desktop Guided Tour"),
            NULL);

        return 1;
    }

    ShowWindow(hWnd, nCmdShow);
    UpdateWindow(hWnd);

    //Prevent the window from instant closing.
    //while (true) {
    //    Sleep(1);
    //}
};

LRESULT CALLBACK WndProc(
    HWND hWnd,
    UINT message,
    WPARAM wParam,
    LPARAM lParam
) {
    return 0;
};