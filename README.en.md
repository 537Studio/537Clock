# 537Clock

#### Introduction

537 Clock is a Windows console application developed by 537 Studio, which is a command-line interface with functions such as year, month, day, hour, minute, and second display, Unix timestamp display, timing/clearing, and color grading.

Released on December 31, 2023

Latest official version: 1.1 (portable: x64 & x86)

Video introduction: https://www.bilibili.com/video/BV1Y2421M7yk, or see the end of the document.

#### Concept: Less is more

The software is designed to create a great user experience. Icons built with useful characters and a user-friendly UI (user interface) that can be used to adjust the foreground color of the console (display character color). Its interactive experience also goes beyond the interaction of most command-line programs, such as selecting in-menu functions, where a normal command-line program requires the user to enter text before entering, while the 537 stopwatch cleverly uses a keyboard listening algorithm to react immediately when the software window is active. This greatly facilitates the use of the software. For example, during the timing period, the user presses and holds the spacebar for about 1 second (long press to avoid accidental touch), and the software will quickly open the pause panel with character animation, showing functions such as clearing and color grading. If you press the corresponding button of the function (not long press), the software will perform the relevant operation.

#### features

At the beginning of the design of the 537 stopwatch, the pursuit of **simplicity and efficiency**. The following are the features and related introductions within the software:

1. **Pause Panel**: Press and hold the keyboard spacebar for about 1 second during the software operation to open the pause panel. There are the following optional functions in the panel: Timer Clear, About, Color Correction, Open 537 Studio Official Website, Open Work Introduction Document, Email, User Agreement, Continue Timer, Exit. Press the buttons corresponding to each function in the first column of the window to perform the corresponding operation. When the pause panel is opened, the ongoing timing operation is paused.

2. **Timer Clear**: The software starts to clock from the moment it runs, and the timer is measured in seconds, which will be displayed in the rightmost column of the window. Press the "T" button on the pause panel to reset the timer time, and when the zero panel is closed, the timer will start from 0 again, which is irreversible.

3. **About**: Press the "A" button on the pause panel to display the software icon, version and other related information, and there will be a selection sound and a software startup sound when displaying, and there will be a comfortable character animation. After 0.2 seconds after the character interface is displayed, the software will automatically pop up an About window, which will display the current system information and software information, click "Confirm" to close. This window is a normal window type that can be preserved without conflicting with the stopwatch itself, and you can still perform other operations within the main window of the software even if you don't close the window.

4. Color Grading (removed from version 1.1): Press the "C" button in the pause panel to perform the action. This option provides the ability to adjust the foreground color (color of the displayed text) of the console window by pressing the corresponding hexadecimal key (0-9, A-F), and the following colors are available:

- 0 = black 8 = gray
    - 1 = Blue 9 = Light blue
    - 2 = Green A = Pale Green (default text color for 537 stopwatch)
    - 3 = light green B = light light green
    - 4 = Red C = Light red
    - 5 = Purple D = Lilac
    - 6 = Yellow E = Pale Yellow
    - 7 = White F = Bright White

> **Note**: The color description comes from the built-in Command Prompt program (cmd.exe) of the Microsoft Windows operating system, and the actual display color may not be the same as the description color.
> 537 Stopwatch does not store color data, and the text color will revert to pale green after restarting.

5. **Open the official website of 537 Studio**: Press the "W" button in the pause panel to perform the operation (https://www.537studio.com) of opening the 537 official website with the default browser of the system, and the website will be online in the future The web online help document of the "537 Stopwatch" software will be launched, but the relevant documents are still unfinished. This is just a test feature.

6. **Email**: Press the "e" button in the pause panel, the program will call the system's default email sending software (such as mail App, Outlook, etc.), and automatically create an email session, the recipient is the developer's mailbox (wushaoquan666@outlook.com), the email function is designed to allow users to get in touch with the developer, send error messages, questions, etc. for help and support.

7. **User Agreement**: Press the "L" button in the pause panel. This software uses the GNU GPL-3.0 open source license, and the open source license web page (https://www.gnu.org/licenses/lgpl-3.0-standalone.html) will be opened using the default browser of the system.
    - The Software is open sourced on the Gitee platform under the GPL-3.0 Open Source License and is available for modification and distribution by anyone (https://gitee.com/FTS-537Studio/537Clock).

8. **Open Source Website** (for version 1.1 and above): Press the "o" button in the pause panel, and all the code repository addresses of the software (including Gitee, GitHub) will be displayed. Press the corresponding button, and the software will use the system's default browser to open the relevant Git repository web page.

9. Clear Screen (for 1.1 and later): Pressing the "S" button in the pause panel will clear the screen with text animation and restore the state when the software was opened. Your timing data will be saved.

10. **Continue Timing**: If the user presses the spacebar by mistake or just wants to pause the timer, they can press the "X" key in the pause panel to restore the original timer.

11. **Exit**: To exit the software, you can press the "Q" key to exit in the pause panel. After exiting, the timekeeping time and color settings will not be saved.

#### Development

Development Environment:D ev-C++ 5.11 with TDM-GCC(MinGW) 4.9.2

**Deployment System**: Windows XP and above

Language Standard: ISO C++11

Compiler extra link directive: -lwinmm

##### How can I participate in the development?

Join Studio 537 (hello@537studio.com) or submit a modification request.

#### Help

If you encounter additional questions or update suggestions, please email hello@537studio.com. We will continue to improve.

<iframe src="//player.bilibili.com/player.html?isOutside=true&aid=1601337036&bvid=BV1Y2421M7yk&cid=1457691800&p=1" scrolling="no" border="0" frameborder="no" framespacing="0" allowfullscreen="true"></iframe>