package crud;

import java.io.IOException;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;


public class UserRegisterServelet extends HttpServlet {
	private static final long serialVersionUID = 1L;

	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		request.getRequestDispatcher("user-register.jsp").forward(request, response);		
	}

	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		String email = request.getParameter("email");
		String password = request.getParameter("password");
		String[] birthday = request.getParameter("birthday").replace(" ", "/").replace("-", "/").split("/");
		
		User[] users = Database.getUsers();
	
		// unique user
		for (User user: users) {
			if (user != null && user.getEmail().equals(email)) {
				request.setAttribute("msg-erro", "Email já cadastrado.");
				request.getRequestDispatcher("erro.jsp").forward(request, response);
				return;
			}
		}
		
		try {
			// validating birthday
			Date birth = new Date(Integer.parseInt(birthday[0]), Integer.parseInt(birthday[1]), Integer.parseInt(birthday[2]));
			// new user
			User user = new User(email, password, birth);
			// to database
			Database.insert(user);
		} catch (IllegalArgumentException e) {
			request.setAttribute("msg-erro", "Data enviada não é válida.");
			request.getRequestDispatcher("erro.jsp").forward(request, response);
			return;
		} catch (ArrayIndexOutOfBoundsException e) {
			request.setAttribute("msg-erro", "Data enviada não está completa. Tente dd/mm/yyyy.");
			request.getRequestDispatcher("erro.jsp").forward(request, response);
			return;
		}
		
		request.getRequestDispatcher("home.jsp").forward(request, response);
		return;				
	}
}
