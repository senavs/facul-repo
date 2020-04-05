import java.io.IOException;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

@WebServlet("/valida-usuario")
public class ValidaUsuario extends HttpServlet {
	private static final long serialVersionUID = 1L;
	private static String USUARIO = "admin";
	private static String SENHA = "123";
       
    public ValidaUsuario() {
        super();
    }

	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		String new_usuario = request.getParameter("usuario");
		String new_senha = request.getParameter("senha");
		
		if (USUARIO.equals(new_usuario) && SENHA.equals(new_senha)) {
			response.sendRedirect("calcular-idade.html");
		} else {
			response.sendRedirect("login-error.html");
		}
		
	}

}
