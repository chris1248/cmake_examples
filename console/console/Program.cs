using System;
using System.Runtime.InteropServices;

namespace console
{
	class Program
	{
		static void Main(string[] args)
		{
			Console.WriteLine("Hello World!");

			TryPInvoke();
		}

		// ================================================
		// PInvoke 
		// ================================================

		[DllImport("../../lib/libSharedLib.so")]
		private static extern UInt32 Factorial(UInt32 val);

		[DllImport("../../lib/libSharedLib.so")]
		private static extern void TestSharedMethod();

		[DllImport("../../lib/libSharedLib.so")]
		private static extern double Multiply(float x,float y);

		[DllImport("../../lib/libSharedLib.so", CharSet = CharSet.Auto)]
		private static extern void PrintString(string s);

		// For returning a string, an Ansi string is the only one that works.
		// I couldn't get it to work with a wchar_t* type. It would only return
		// the first character of the string.
		[DllImport("../../lib/libSharedLib.so", CharSet = CharSet.Ansi)]
		//[return: MarshalAs(UnmanagedType.LPStr)]
		private static extern string GetString();

		private static void TryPInvoke()
		{
			// MessageBox(IntPtr.Zero, "Hi there", "Another message", 0);
			UInt32 result = Factorial(6);
			Console.WriteLine("Factorial of 6 = {0}", result);
			TestSharedMethod();
			double product = Multiply(3.0f, 6.0f);
			Console.WriteLine("Product of 3.0 and 6.0: {0:0.00}", product);

			PrintString("From .NetCore with love");

			string msg = GetString();
			Console.WriteLine("GetString: {0}", msg);
		}
	}
}
