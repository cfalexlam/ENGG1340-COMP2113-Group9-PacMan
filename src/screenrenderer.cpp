// Receive and convert keyboard input into move and decide further actions
void ScreenRenderer::KeyboardModeOpen(){ // in keyboardmode, use printw(mystring.c_str()) instead of cout<< mystring

    initscr(); //initialize screen
    noecho(); // no input display
}
void ScreenRenderer::KeyboardModeWb(){
    
    nodelay(stdscr,false); /* Takes keyboard input with blocking or delay */
    keypad(stdscr,false) // not allow arrow key
}
void ScreenRenderer::KeyboardModeNb(){

    nodelay(stdscr,true); /* Takes keyboard input without blocking or delay */
    keypad(stdscr,true) // allow arrow key
}
void ScreenRenderer::KeyboardModeClose(){
    endwin();
}

string ScreenRenderer::takeCmdInput(string message){
    cout << message << endl;
    cin >> x;
    return x
}

