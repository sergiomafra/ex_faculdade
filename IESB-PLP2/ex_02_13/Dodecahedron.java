import java.lang.Math;

public class Dodecahedron {
	
	private double edge;

	public Dodecahedron() {
		this.edge = 1.0;
	}

	public Dodecahedron(double edge) {
		this.edge = edge;
	}

	public double getEdge() {
		return edge;
	}

	public void setEdge(double edge) {
		this.edge = edge;
	}

	public double area() {
		return 3*Math.pow(25+10*Math.pow(5,1.0/2),1.0/2)*Math.pow(this.edge,2);
	}

	public double volume() {
		return (1.0/4)*(15+7*Math.pow(5,1.0/2))*Math.pow(this.edge,3);
	}

	public static void main(String[] args) {
		Dodecahedron dod_one = new Dodecahedron();
		Dodecahedron dod_two = new Dodecahedron(1.5);

		System.out.println("dot_one");
		System.out.printf("\tEdge: %f", dod_one.getEdge());
		System.out.printf("\n\tArea: %f", dod_one.area());
		System.out.printf("\n\tVolume: %f", dod_one.volume());
		dod_one.setEdge(3.0);
		System.out.printf("\n\tNew edge: %f", dod_one.getEdge());
		System.out.printf("\n\tNew area: %f", dod_one.area());
		System.out.printf("\n\tNew volume: %f\n", dod_one.volume());

		System.out.println("\ndot_two");
		System.out.printf("\tEdge: %f", dod_two.getEdge());
		System.out.printf("\n\tArea: %f", dod_two.area());
		System.out.printf("\n\tVolume: %f", dod_two.volume());
		dod_two.setEdge(5.3);
		System.out.printf("\n\tNew edge: %f", dod_two.getEdge());
		System.out.printf("\n\tNew area: %f", dod_two.area());
		System.out.printf("\n\tNew volume: %f\n", dod_two.volume());
	}

}