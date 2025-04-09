<%@ page contentType="text/html; charset=ISO-8859-1"%>
<%@ page session="false" %>
//to really show that session tracking is turned off
<!DOCTYPE html>
<html>
<head>
    <title>Counter with Hidden Field</title>
    <script>
        function update(event) {
            event.preventDefault();

            const counterInput = document.querySelector('input[name="counter"]');
            let counter = parseInt(counterInput.value, 10);
            const action = event.submitter.value; 

            // Update the counter based on the action
            if (action === 'prev') {
                counter--; // Decrease counter
            } else if (action === 'next') {
                counter++; // Increase counter
            }

            counterInput.value = counter;
            document.getElementById("display").innerHTML="Current Counter Value: "+String(counter);

        }
    </script>
</head>
<body>

    <h1 id="display">Current Counter Value: 0</h1>

    <!-- Form to submit "next" and "prev" actions with hidden field to pass the counter -->
    <form onsubmit="update(event)">
        <!-- Hidden field to store the current counter -->
        <input type="hidden" name="counter" value="0">
        <input type="submit" name="action" value="prev"> <!-- Decrease counter -->
        <input type="submit" name="action" value="next"> <!-- Increase counter -->
    </form>

</body>
</html>
