package ex4_10;

import java.util.TreeMap;

/**
 *
 * @author sergio
 */

public class Converter {
    
    private final static TreeMap<Integer, String> ROMAN_MATCH = new TreeMap<Integer, 
            String>();
    static {
        ROMAN_MATCH.put(900, "CM");
        ROMAN_MATCH.put(500, "D");
        ROMAN_MATCH.put(400, "CD");
        ROMAN_MATCH.put(100, "C");
        ROMAN_MATCH.put(90, "XC");
        ROMAN_MATCH.put(50, "L");
        ROMAN_MATCH.put(40, "XL");
        ROMAN_MATCH.put(10, "X");
        ROMAN_MATCH.put(9, "IX");
        ROMAN_MATCH.put(5, "V");
        ROMAN_MATCH.put(4, "IV");
        ROMAN_MATCH.put(1, "I");
    }
    
    private final static TreeMap<Integer, String> HANDWRITTING_MATCH = new TreeMap<Integer, 
            String>();
    
    static {
        HANDWRITTING_MATCH.put(900, "novecentos");
        HANDWRITTING_MATCH.put(800, "oitocentos");
        HANDWRITTING_MATCH.put(700, "setecentos");
        HANDWRITTING_MATCH.put(600, "seiscentos");
        HANDWRITTING_MATCH.put(500, "quinhentos");
        HANDWRITTING_MATCH.put(400, "quatrocentos");
        HANDWRITTING_MATCH.put(300, "trezentos");
        HANDWRITTING_MATCH.put(200, "duzentos");
        HANDWRITTING_MATCH.put(100, "cento");
        HANDWRITTING_MATCH.put(90, "noventa");
        HANDWRITTING_MATCH.put(80, "oitenta");
        HANDWRITTING_MATCH.put(70, "setenta");
        HANDWRITTING_MATCH.put(60, "sessenta");
        HANDWRITTING_MATCH.put(50, "cinquenta");
        HANDWRITTING_MATCH.put(40, "quarenta");
        HANDWRITTING_MATCH.put(30, "trinta");
        HANDWRITTING_MATCH.put(20, "vinte");
        HANDWRITTING_MATCH.put(19, "dezenove");
        HANDWRITTING_MATCH.put(18, "dezoito");
        HANDWRITTING_MATCH.put(17, "dezessete");
        HANDWRITTING_MATCH.put(16, "dezesseis");
        HANDWRITTING_MATCH.put(15, "quinze");
        HANDWRITTING_MATCH.put(14, "catorze");
        HANDWRITTING_MATCH.put(13, "treze");
        HANDWRITTING_MATCH.put(12, "doze");
        HANDWRITTING_MATCH.put(11, "onze");
        HANDWRITTING_MATCH.put(10, "dez");
        HANDWRITTING_MATCH.put(9, "nove");
        HANDWRITTING_MATCH.put(8, "oito");
        HANDWRITTING_MATCH.put(7, "sete");
        HANDWRITTING_MATCH.put(6, "seis");
        HANDWRITTING_MATCH.put(5, "cinco");
        HANDWRITTING_MATCH.put(4, "quatro");
        HANDWRITTING_MATCH.put(3, "três");
        HANDWRITTING_MATCH.put(2, "dois");
        HANDWRITTING_MATCH.put(1, "um");
        
    }
    
    private final static TreeMap<Integer, String> ORDINALS_MATCH = new TreeMap<Integer, 
            String>();
    
    static {
        ORDINALS_MATCH.put(900, "nongentésimo");
        ORDINALS_MATCH.put(800, "octigentésimo");
        ORDINALS_MATCH.put(700, "septigentésimo");
        ORDINALS_MATCH.put(600, "seiscentésimo");
        ORDINALS_MATCH.put(500, "quingentésimo");
        ORDINALS_MATCH.put(400, "quadrigentésimo");
        ORDINALS_MATCH.put(300, "tricentésimo");
        ORDINALS_MATCH.put(200, "ducentésimo");
        ORDINALS_MATCH.put(100, "centésimo");
        ORDINALS_MATCH.put(90, "nonagésimo");
        ORDINALS_MATCH.put(80, "octogésimo");
        ORDINALS_MATCH.put(70, "septuagésimo");
        ORDINALS_MATCH.put(60, "sexagésimo");
        ORDINALS_MATCH.put(50, "quinquagésimo");
        ORDINALS_MATCH.put(40, "quadragésimo");
        ORDINALS_MATCH.put(30, "trigésimo");
        ORDINALS_MATCH.put(20, "vigésimo");
        ORDINALS_MATCH.put(10, "décimo");
        ORDINALS_MATCH.put(9, "nono");
        ORDINALS_MATCH.put(8, "oitavo");
        ORDINALS_MATCH.put(7, "sétimo");
        ORDINALS_MATCH.put(6, "sexto");
        ORDINALS_MATCH.put(5, "quinto");
        ORDINALS_MATCH.put(4, "quarto");
        ORDINALS_MATCH.put(3, "terceiro");
        ORDINALS_MATCH.put(2, "segundo");
        ORDINALS_MATCH.put(1, "primeiro");
    }
    
    public String romanConversion(int base_number) {
        int i = ROMAN_MATCH.floorKey(base_number);
        if(base_number == i) {
            return ROMAN_MATCH.get(base_number);
        }
        return ROMAN_MATCH.get(i) + romanConversion(base_number - i);
    }
    
    public String handwrittingConversion(int base_number) {
        int j = HANDWRITTING_MATCH.floorKey(base_number);
        if(base_number == 100) {
            return "cem";
        }
        if(base_number == j) {
            return HANDWRITTING_MATCH.get(base_number);
        }
        return HANDWRITTING_MATCH.get(j) + " e " + handwrittingConversion(base_number - j);
    }
    
    public String ordinalsConversion(int base_number) {
        int k = ORDINALS_MATCH.floorKey(base_number);
        if(base_number == k) {
            return ORDINALS_MATCH.get(base_number);
        }
        return ORDINALS_MATCH.get(k) + " " + ordinalsConversion(base_number - k);
    }
}