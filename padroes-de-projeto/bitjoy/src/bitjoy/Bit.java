package bitjoy;

public class Bit {
	int value; 
	
	public Bit(int value) {
		if (value > 0) {
			this.value = 1;
		} else {
			this.value = 0;
		}
	}
	
	public Bit sum(Bit other) {
		return new Bit(this.value + other.value);
	}
	
	public boolean isEqual(Bit other) {
		return this.value == other.value;
	}
}
