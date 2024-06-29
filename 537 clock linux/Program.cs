using System;
using System.Diagnostics;

class Program
{
    static void Main()
    {
        // 获取当前控制台窗口的高度和宽度
        int windowHeight = Console.WindowHeight;
        int windowWidth = Console.WindowWidth;

        Console.WriteLine("欢迎使用537 Studio 开发的537秒表(基于C# .NET) Linux 特供版");
        Console.WriteLine("当前窗口的高度是：" + windowHeight + "宽度是：" + windowWidth);
        Console.WriteLine("开发者：Yilihamujiang365@outlook.com");
        Console.WriteLine();
        Console.WriteLine("Copyright © 537 studio .2023-2024  All Rights Reserved");
        Console.WriteLine();

        Console.WriteLine("t 开始计时");
        Console.WriteLine("a 关于");
        Console.WriteLine("w 打开537工作室官网");
        Console.WriteLine("h 打开在线网站帮助文档");
        Console.WriteLine("e 电子邮件");
        Console.WriteLine("l 用户协议");
        Console.WriteLine("o 项目网站");
        Console.WriteLine("s 清空屏幕");
        Console.WriteLine("q 退出软件");

        string userinput = Console.ReadLine() ?? string.Empty;



////////////////////////////////////////////////////////////////////
 /// <summary>
/// 使用系统的默认浏览器打开指定的网页。
/// </summary>
/// <param name="url">要打开的网页的URL。</param>
    static void OpenWebsite(string url)
    {
        // 使用默认浏览器打开网址
        ProcessStartInfo psi = new ProcessStartInfo
        {
            FileName = url,
            UseShellExecute = true
        };
        Process.Start(psi);
    }
////////////////////////////////////////////////////////////////////



        if (userinput.ToLower() == "t")
        {
            // 记录开始时间
            DateTime startTime = DateTime.Now;
            bool running = true;          
            Console.WriteLine (">>    年  月  日      时   分   秒                         Unix时间戳                      计时");           
            while (running)
            {
                // 检查是否有键按下
                if (Console.KeyAvailable)
                {
                    ConsoleKeyInfo keyInfo = Console.ReadKey(true);
                    if (keyInfo.Key == ConsoleKey.B)
                    {
                        running = !running; // 切换运行状态
                        Console.WriteLine(running ? "继续" : "暂停");
                    }
                }

                DateTimeOffset now = DateTimeOffset.UtcNow;
                long unixTime = now.ToUnixTimeSeconds();
                TimeSpan elapsed = DateTime.Now - startTime;

                Console.WriteLine(DateTime.Now.ToString("  yyyy年MM月dd日    HH时:mm分:ss秒     ") + "537 Studio    " +"1970年1月1日距今" + unixTime + "秒          " + elapsed.TotalSeconds + "秒");

                // 等待1秒
                System.Threading.Thread.Sleep(1000);
            }
        }

        // 其他命令的处理逻辑...

        //Console.WriteLine("程序已退出。");
   
    //("a 关于");
        if (userinput.ToLower() == "a")
        {
        Console.WriteLine (">>537秒表（537Clock）Linux特供版 是537工作室开发的一款Linux控制台应用程序，为命令行界面，有年月日时分秒显示、Unix时间戳显示、计时/清零等功能。发布于2024年05月29日");  
        }

        
    //("w 打开537工作室官网");
        if (userinput.ToLower() == "w")
        {
            OpenWebsite("https://www.537studio.com/");
        }


    //("h 打开在线网站帮助文档");
        if (userinput.ToLower() == "h")
        {
            Console .WriteLine ("由于537官网暂未公布在线文档链接🔗地址，所以此连接指向了官网，后续版本会更新");
           OpenWebsite ("https://gitee.com/FTS-537Studio/537Clock");
        }



    //("e 电子邮件");
        if (userinput.ToLower() == "e")
        {
           Console.WriteLine ("E-mail:yilihamujiang365@outlook.com");
           Console.WriteLine ("E-mail:wushaoquan666@outlook.com");
          
        }

    //("l 用户协议");
        if (userinput.ToLower() == "l")
        {
          OpenWebsite("https://www.gnu.org/licenses/lgpl-3.0-standalone.html") ;
        }


    //("o 项目网站");
        if (userinput.ToLower() == "o")
        {
            OpenWebsite("https://gitee.com/FTS-537Studio/537Clock");
        }
   
    //("s 清空屏幕");
        if (userinput.ToLower() == "s")
        {
           Console.Clear(); // 清空屏幕
           Console.WriteLine("屏幕已被清空。");
        }

    //("q 退出软件");
        if (userinput.ToLower() == "q")
        {
             Environment.Exit(0);
        }
    }
} 