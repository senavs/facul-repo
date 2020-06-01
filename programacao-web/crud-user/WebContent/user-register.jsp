<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>

<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
	<head>
		<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
		<title>User - Register</title>
	</head>
	<body>
		<div style="text-align: center;">
			<fieldset style="display: inline;">
				<form action="user-register" method="post">
					<label>Email</label>
					<input type="email" name="email" required>
					<br><br>
					<label>Password</label>
					<input type="password" name="password" required>
					<br><br>
					<label>Birthday</label>
					<input type="text" name="birthday" required>
					<br><br>
					<input type="submit" value="enviar">
				</form>
			</fieldset>
		</div>
	</body>
</html>