<%@ page contentType="text/html; charset=ISO-8859-1"%>
<%@ page session="false" %>
<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>Counter with Next and Prev</title>
  <script>   
    // Function to get the count from the URL
    function getCountFromURL() {
      const params = new URLSearchParams(window.location.search);
      let count = parseInt(params.get('count'), 10);
      if (isNaN(count)) {
        count = 0;  // Default value if no count is specified
      }
      return count;
    }
    
    // Initialize the counter when the page loads
    window.onload = function () {
      const count = getCountFromURL();
      updateCounter(count);
    }

    // Function to update the URL based on the next/previous count
    function updateURL(count) {
      history.pushState(null, null, "?count=" + count);
    }

    // Function to increase count
    function nextCount() {
      let count = getCountFromURL();
      count++;
      updateCounter(count);
    }

    // Function to decrease count
    function prevCount() {
      let count = getCountFromURL();
      count--;
      updateCounter(count);
    }

    // Function to update the displayed counter and the URL
    function updateCounter(count) {
      document.getElementById('counter').textContent = count;
      updateURL(count);
    }

    
  </script>
</head>
<body>

<h1>Current Counter Value: <span id="counter">0</span></h1>

<form>
    <button type="button" onclick="prevCount()">Prev</button>
    <button type="button" onclick="nextCount()">Next</button>
</form>


</body>
</html>
