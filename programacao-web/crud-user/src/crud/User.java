package crud;

import com.google.gson.Gson;

public class User {
	
	private int id;
	private String email;
	private String password;
	private Date birthday;
	
	public User(String email, String password, Date birthday) {
		this.email = email;
		this.password = password;
		this.birthday = birthday;
	}
	
	public int getId() {
		return id;
	}
	
	public void setId(int id) {
		this.id = id;
	}
	
	public String getEmail() {
		return email;
	}

	public String getPassword() {
		return password;
	}
	
	public void setPassword(String password) {
		this.password = password;
	}

	public Date getBirthday() {
		return birthday;
	}
	
	public boolean checkPassword(String password) {
		return password.equals(this.password);
	}
	
	public String toJson() {
		Gson gson = new Gson();
		return gson.toJson(this);
	}

	public static User fromJson(String json) {
		Gson gson = new Gson();
		User user = gson.fromJson(json, User.class);
		return user;
	}

}
