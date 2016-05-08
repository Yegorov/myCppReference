using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp
{
    class Program
    {
        [DllImport(@"C:\Users\Admin\Desktop\TestProject\mydll.dll", 
            CallingConvention = CallingConvention.Cdecl, EntryPoint = "hello")]
        public static extern int hello();

        [DllImport(@"C:\Users\Admin\Desktop\TestProject\mydll.dll", 
            CallingConvention = CallingConvention.Cdecl, EntryPoint = "sum")]
        public static extern int sum(int a, int b, byte[] bytes);

        [DllImport(@"C:\Users\Admin\Desktop\TestProject\mydll.dll",
            CallingConvention = CallingConvention.Cdecl, EntryPoint = "getbyte")]
        public static extern byte getbyte(byte a);
        static void Main(string[] args)
        {
            IntPtr ptr;
            
            Console.WriteLine("Hello world");
            byte[] bytes = new byte[5];
            Console.WriteLine("Sum = " + sum(10, 20, bytes));
            byte b = getbyte(40);
            Console.ReadKey();
        }
    }
}
