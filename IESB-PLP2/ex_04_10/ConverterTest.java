package ex4_10;

/**
 *
 * @author sergio
 */

public class ConverterTest {
    
    public static void main(String[] args) {
        
        Converter conv = new Converter();
        System.out.printf("%s\n", conv.romanConversion(100));
        System.out.printf("%s\n", conv.handwrittingConversion(100));
        System.out.printf("%s\n", conv.ordinalsConversion(99));
    }
    
}
