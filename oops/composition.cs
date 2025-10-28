using System;
using System.Collections.Generic;
using System.Linq;
using System.Text.RegularExpressions;

namespace HelloWorld
{
  
  public class Frame
  {
    public string Material {get; set;}
    
    public Frame(string material){
      Material = material;
    }
  }
  
  
  public class Suspension
  {
    public string brand {get; set;}
    
    public void AbsorbShock(){
      Console.WriteLine("Shock is Absorbed");
    }
  }
  
  
  public class Bicycle{
    public Frame _frame;
    public Suspension _suspension;
    
    public Bicycle(Frame frame, Suspension suspension){
      _frame = frame;
      _suspension = suspension;
    }
    
    public void Ride(){
      Console.WriteLine($"Riding bicycle with {_frame.Material} frame type");
      _suspension.AbsorbShock();
    }
  }
  
  
  
	public class Program
	{
		public static void Main(string[] args)
		{
		  var frame = new Frame("Steel");
		  var suspension = new Suspension();
		  
		  var bike = new Bicycle(frame, suspension);
		  bike.Ride();
		}
	}
}
