package bitjoy;

import bitjoy.Bit;
import bitjoy.Adder;

public class Bytes {
	
	private Bit[] bits;
	
	public Bytes(Bit[] bits) {
		// Bytes class can only pass Bytes[8]
		this.bits = bits;		
	}
	
	public Bytes add(Bytes other) {
		Bit[] this_bits = this.bits;
		Bit[] other_bits = other.bits;
		
		Bit[] result = new Bit[8];
		for (int i = 1; i <= 8; i++) {
			Bit[] addition = new Bit[3];
			// addition == (sum, carry)
			if (i == 1) {
				addition = Adder.full(this_bits[8 - i], other_bits[8 - i], new Bit(0));
			} else {
				addition = Adder.full(this_bits[8 - i], other_bits[8 - i], addition[1]);
			}
			result[8 - i] = addition[0];
		}
		return new Bytes(result);
	}
}
