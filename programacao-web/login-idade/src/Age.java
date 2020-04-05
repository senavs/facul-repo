public class Age {
	
	public static int calculate(Date today, Date birth) throws RuntimeException{
		int age = today.getYear() - birth.getYear();
		
		if (today.getMonth() < birth.getMonth()) {
			age--;
		} else if (today.getDay() < birth.getDay()) {
			age--;
		}
		
		if (age < 0) {
			throw new RuntimeException("Data de nascimento futura.");
		}
		
		return age;
	}
	
}
