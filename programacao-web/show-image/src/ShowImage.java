import java.io.File;
import java.io.IOException;
import java.nio.file.Files;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

@WebServlet("/me")
public class ShowImage extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    public ShowImage() {
        super();
    }

	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		String file_path = "/home/sena/Pictures/me-linkedin.jpeg";
		File file = new File(file_path);
		byte[] fileContent = Files.readAllBytes(file.toPath());

		response.setContentType("image/jpeg");
		response.getOutputStream().write(fileContent);
	}

}
