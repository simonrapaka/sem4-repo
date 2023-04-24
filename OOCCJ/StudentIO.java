import java.io.*;

class Student{
	int rno;
	String name;
	int[] marks = new int[5];
}

public class StudentIO {
	public static void main(String[] args) throws Exception {
		InputStreamReader in = new InputStreamReader(System.in);
		BufferedReader br = new BufferedReader(in);
		PrintStream pr = new PrintStream("d.txt");

		System.out.print("Enter number of Students: ");
		int n = Integer.parseInt(br.readLine());

		for(int j=0;j<73;j++) pr.printf("-");
		pr.printf("%n");
		pr.printf("| %4s | %-30s | %7s | %11s | %5s |\n", "S.No","Name","Roll No","Total Marks","Grade");
		for(int j=0;j<73;j++) pr.printf("-");
		pr.printf("%n");

		for(int i=0;i<n;i++){
			Student s = new Student();

			System.out.print("\nEnter details of "+(i+1));
			switch ((i+1)%10) {
				case 1:
					System.out.print("st");
					break;

				case 2:
					System.out.print("nd");
					break;

				case 3:
					System.out.print("rd");
					break;

				default:
					System.out.print("th");
					break;
			}
			System.out.print(" Student\n");

			System.out.print("\nRoll No: ");
			s.rno = Integer.parseInt(br.readLine());

			System.out.print("\nName: ");
			s.name = br.readLine();

			System.out.print("\nMarks:\n");
			for(int j=0;j<5;j++){
				System.out.print("Subject "+(j+1)+": ");
				s.marks[j] = Integer.parseInt(br.readLine());
			}
			int avg = 0;

			for(int j=0;j<5;j++)
				avg+=s.marks[j];

			avg/=5;
			
			String g = new String();

			if(avg >= 90) g = "A";
			if(avg >= 80 && avg < 90) g = "B";
			if(avg >= 70 && avg < 80) g = "C";
			if(avg >= 60 && avg < 70) g = "D";
			if(avg < 60) g = "Fail";

			pr.printf("| %4s | %-30s | %7s | %11s | %5s |\n", Integer.toString(i+1),s.name,Integer.toString(s.rno),Integer.toString(avg*5),g);
			for(int j=0;j<73;j++) pr.printf("-");
			pr.printf("%n");
		}
		pr.close();
		br.close();
		in.close();

		Runtime c = Runtime.getRuntime();
		c.exec("cmd /c notepad d.txt");
	}
}
