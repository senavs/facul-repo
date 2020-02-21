package bitjoy;

import bitjoy.Bit;

public class LogicalOperator {
	
	public static Bit not(Bit bit) {
		if (bit.value == 1) {
			return new Bit(0);
		} else {
			return new Bit(1);
		}
	}
	
	public static Bit or(Bit bit1, Bit bit2) {
		return bit1.sum(bit2);
	}
	
	public static Bit and(Bit bit1, Bit bit2) {
		Bit gate1 = not(or(bit1, bit2));
		Bit gate2 = not(or(bit2, bit1));
		Bit gate3 = not(or(gate1, gate2));
		return gate3;
	}
	
	public static Bit nand(Bit bit1, Bit bit2) {
		return not(and(bit1, bit2));
	}
	
	public static Bit xor(Bit bit1, Bit bit2) {       
		Bit gate1 = nand(bit1, bit2);
        Bit gate2 = or(bit1, bit2);
        Bit gate3 = and(gate1, gate2);
        return gate3;
	}
	
	public static Bit xorn(Bit bit1, Bit bit2) {
		return not(xor(bit1, bit2));
	}
}
