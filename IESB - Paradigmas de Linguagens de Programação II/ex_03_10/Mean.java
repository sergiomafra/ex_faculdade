import java.lang.Math;
import java.util.Scanner;

public class Mean {
	protected int values[] = new int[4];

	public Mean() {

	}

	public Mean(int[] values) {
		setValues(values);
	}

	public int[] getValues() {
		return values;
	}

	public void setValues(int[] values) {
		this.values = values;
	}

	public String toString() {
		return "Nâo funcionou.";
	}

	class ArithmeticMean extends Mean {

		public ArithmeticMean(int[] values) {
			super(values);
		}

		public double calcArithmeticMean() {
			int sum = 0;
			for(int i = 0; i < 4; i++) {
				sum = sum + values[i];
			}

			return sum / 4.0;
		}

		public String toString() {
			return "A média aritmética é " + calcArithmeticMean();
		}

	}

	class GeometricMean extends Mean {

		public GeometricMean(int[] values) {
			super(values);
		}

		public double calcGeometricMean() {
			int mult = 1;
			for(int i = 0; i < 4; i++) {
				mult = mult * values[i];
			}
			return Math.pow(mult,1.0/4);
		}

		public String toString() {
			return "A média geométrica é " + calcGeometricMean();
		}

	}

	class HarmonicMean extends Mean {

		public HarmonicMean(int[] values) {
			super(values);
		}

		public double calcHarmonicMean() {
			double sum = 0;
			for(int i = 0; i < 4; i++) {
				sum = sum + 1.0/values[i];
			}
			return 4.0 / sum;
		}

		public String toString() {
			return "A média harmônica é " + calcHarmonicMean();
		}
	}

	public void execute() {
		int values[] = new int[4];
		Scanner scanner = new Scanner(System.in);

		for(int i = 0; i < 4; i++) {
			System.out.printf("Digite um número inteiro: ");
			values[i] = scanner.nextInt();
		}

		ArithmeticMean arithmetic = new ArithmeticMean(values);
		GeometricMean geometric = new GeometricMean(values);
		HarmonicMean harmonic = new HarmonicMean(values);

		System.out.printf("\n%s\n", arithmetic.toString());
		System.out.printf("\n%s\n", geometric.toString());
		System.out.printf("\n%s\n", harmonic.toString());
		
	}

	public static void main(String[] args) {
		Mean mean = new Mean();
		mean.execute();
	}
}

