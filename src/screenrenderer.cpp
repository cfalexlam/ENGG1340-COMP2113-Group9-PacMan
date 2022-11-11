// Receive and convert keyboard input into move and decide further actions
void ScreenRenderer::KeyboardMode(){
    /* Takes keyboard input without blocking or delay */
    initscr(); // 
    noecho(); // no input display
    nodelay(stdscr,true); // no blocking or delay
    keypad(stdscr,true) // allow arrow key
}

string ScreenRenderer::takeCmdInput(string message){
    cout << message << endl;
    cin >> x;
    return x
}
string ScreenRenderer::CmdMode(){
    endwin();
}
