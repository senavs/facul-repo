import java.io.IOException;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;


@WebServlet("/original")
public class Original extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    public Original() {
        super();
    }

	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		String to = request.getParameter("to");
		
		if (to == null) {
			response.getWriter().append("você não especificou sua rota. utilize \"?to=redirect01\" ou \"?to=redirect02\"");
		} else if (to.equals("redirect01")) {
			RequestDispatcher redirect = request.getRequestDispatcher("redirect01?from=original");
			redirect.forward(request, response);
		} else if (to.equals("redirect02")) {
			response.sendRedirect(request.getContextPath() + "/redirect02?from=original");
		} else {
			response.getWriter().append("você não especificou sua rota corretamente. utilize \"?to=redirect01\" ou \"?to=redirect02\"");
		}
		
	}

}
