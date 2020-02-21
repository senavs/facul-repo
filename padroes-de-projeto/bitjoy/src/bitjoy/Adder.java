package bitjoy;

import bitjoy.LogicalOperator;

public class Adder {
	
	public static Bit[] half(Bit bit1, Bit bit2){
		Bit[] result = new Bit[2];
		
		result[0] = LogicalOperator.xor(bit1, bit2);  // sum
		result[1] = LogicalOperator.and(bit1, bit2);  // carry
		return result;
	}
	
	public static Bit[] full(Bit bit1, Bit bit2, Bit carry) {
		Bit[] result = new Bit[2];
		
		Bit gate1 = LogicalOperator.xor(bit1, bit2);
		Bit gate2 = LogicalOperator.xor(gate1, carry);
		Bit gate3 = LogicalOperator.and(carry, gate1);
		Bit gate4 = LogicalOperator.and(bit1, bit2);
		Bit gate5 = LogicalOperator.or(gate3, gate4);
		
		result[0] = gate2;
		result[1] = gate5;
		return result;
	}

}
