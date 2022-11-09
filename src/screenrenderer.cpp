// Receive and convert keyboard input into move and decide further actions
void ScreenRenderer::takeKeyboardInput(){
    /* Takes keyboard input without blocking or delay */
    if (_kbhit())
        return _getch();
    else
        return -1;
}