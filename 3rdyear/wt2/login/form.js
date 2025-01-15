function validate(){
  // Clear previous error messages
  document.getElementById("error").innerHTML = "";

  // Get the values from the input fields
  var login = document.getElementById("username").value;
  var password = document.getElementById("password").value;
  var flag = true;
  // Regular expression for validating login (alphanumeric + underscore, max 10 characters)
  var loginPattern = /^[a-zA-Z0-9_]{1,10}$/;

  // Check if login is valid
  if (!loginPattern.test(login)) {
      document.getElementById("error").innerHTML += "\nLogin name must be alphanumeric and can include underscores. It should not exceed 10 characters.";
      document.getElementById("error").style.color = "red";
      flag =  false;  
  }

  // Check if password is valid (length between 6-10, at least one digit, one uppercase letter)
  if (password.length < 6 || password.length > 10) {
      document.getElementById("error").innerHTML += "\nPassword must be between 6 and 10 characters.";
      document.getElementById("error").style.color = "red";
      flag =  false; 
  }

  // Check if password contains at least one digit and one uppercase letter
  var digitPattern = /[0-9]/;
  var uppercasePattern = /[A-Z]/;
  
  if (!digitPattern.test(password) || !uppercasePattern.test(password)) {
      document.getElementById("error").innerHTML += "\nPassword must contain at least one digit and one uppercase letter.";
      document.getElementById("error").style.color = "red";
      flag = false;  
  }

  // If everything is valid
  return flag;
}
