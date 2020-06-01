package crud;

import java.io.IOException;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;


public class UserDeleteServelet extends HttpServlet {
	private static final long serialVersionUID = 1L;
	
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		request.getRequestDispatcher("user-delete.jsp").forward(request, response);
	}

	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		String email = request.getParameter("email");
		
		User[] users = Database.getUsers();
		
		for (User user: users) {
			if (user != null && user.getEmail().equals(email)) {
				Database.delete(user);
				request.getRequestDispatcher("home.jsp").forward(request, response);
				return;
			}
		}
		request.setAttribute("msg-erro", "Email não encontrado.");
		request.getRequestDispatcher("erro.jsp").forward(request, response);
		return;
	}

}