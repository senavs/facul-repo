package crud;

public class Database {
	private static User[] users = new User[32];
	private static int currentUser = 1;
	
	public static User search(int id) {
		return users[id];
	}
	
	public static void insert(User user) {
		user.setId(currentUser);
		users[currentUser] = user;
		currentUser++;
	}
	
	public static void update(User user) {
		users[user.getId()] = user;
	}
	
	public static void delete(User user) {
		users[user.getId()] = null;
	}
	
	public static User[] getUsers() {
		return users;
	}
}
