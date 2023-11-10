
function pisa() {
  h3 = document.createElement('h4');
  h3.textContent = "You will venture into a crazy adventure created by a trio of genius and charismatic crazy people, so be very careful and let's do it...." + " I like it! " + " ...";
  h3.style.color = "green";
  h3.style.fontSize = "30px";
  h3.style.borderBottom = "thick solid green";

  var infoButton = document.getElementById('infoButton');
  if (infoButton) {
    infoButton.style.display = "none";
    document.querySelector('form').parentNode.insertBefore(h3, document.querySelector('form').nextSibling);
  } else {
    console.error("Button with ID 'infoButton' not found.");
  }
}

function buildCompletePath(filename) {
  const currentURL = window.location.href;

  if (!filename.startsWith('http') && !filename.startsWith('/')) {
      const referer = currentURL.endsWith('/') ? currentURL : currentURL + '/';
      filename = referer + filename;
  }

  return filename;
}

function sendDeleteRequest(filename) {
  filename = buildCompletePath(filename);

  fetch(filename, {
      method: 'DELETE',
  })
  .then(response => {
      if (response.ok) {
          return response.text(); // Manejar el caso de éxito
      } else {
          throw new Error('Error al eliminar ' + filename);
      }
  })
  .then(data => {
      // Manejar los datos de la respuesta
      console.log(data);

      // Remove the deleted image from the UI
      const imageElement = document.getElementById(filename);
      if (imageElement) {
          imageElement.parentNode.removeChild(imageElement);
      }

      // Show success message
      const successMessage = document.createElement('h3');
      successMessage.textContent = "Se eliminó " + filename;
      successMessage.style.color = "#00ff00";
      successMessage.style.fontSize = "20px";
      successMessage.style.marginTop = "20px";
      successMessage.style.borderBottom = "thick solid #00ff00";
      document.body.insertBefore(successMessage, document.getElementById('deleteForm'));
  })
  .catch(error => {
      // Mostrar un mensaje de error
      console.error('Error:', error);

      // Show error message
      const errorMessage = document.createElement('h3');
      errorMessage.textContent = "Error al eliminar " + filename;
      errorMessage.style.color = "#ff0000";
      errorMessage.style.fontSize = "20px";
      errorMessage.style.marginTop = "20px";
      errorMessage.style.borderBottom = "thick solid #ff0000";
      document.body.insertBefore(errorMessage, document.getElementById('deleteForm'));
  });
}



function handleFileUpload() {
    const fileInput = document.getElementById('file-upload');
    const imageContainer = document.getElementById('image-container');

    Array.from(fileInput.files).forEach(file => {
        const imageUrl = URL.createObjectURL(file);

        // Create container for image and delete button
        const container = document.createElement('div');

        // Create image element
        const imageElement = document.createElement('img');
        imageElement.src = imageUrl;
        imageElement.alt = file.name;
        imageElement.classList.add('uploaded-image');
        imageElement.id = file.name;

        // Create delete button
        const deleteButton = document.createElement('button');
        deleteButton.textContent = 'Eliminar';
        deleteButton.classList.add('delete-button');
        deleteButton.onclick = function () {
            // Get the filename associated with the delete button
            const filename = imageElement.id;

            // Remove the container element (which includes both the image and delete button)
            container.parentNode.removeChild(container);

            // Trigger the delete request
            sendDeleteRequest(filename);
        };

        // Append image and delete button to the container
        container.appendChild(imageElement);
        container.appendChild(deleteButton);

        // Append the container to the image container
        imageContainer.appendChild(container);
    });
}

// Additional initialization for file input change
document.getElementById('file-upload').addEventListener('change', handleFileUpload);

function ekUpload() {
    function Init() {
        console.log("Upload Initialised");

        var fileSelect = document.getElementById('file-upload'),
            fileDrag = document.getElementById('file-drag'),
            submitButton = document.getElementById('submit-button');

        fileSelect.addEventListener('change', fileSelectHandler, false);

        // Is XHR2 available?
        var xhr = new XMLHttpRequest();
        if (xhr.upload) {
            // File Drop
            fileDrag.addEventListener('dragover', fileDragHover, false);
            fileDrag.addEventListener('dragleave', fileDragHover, false);
            fileDrag.addEventListener('drop', fileSelectHandler, false);
        }
    }

    function fileDragHover(e) {
        var fileDrag = document.getElementById('file-drag');
        e.stopPropagation();
        e.preventDefault();
        fileDrag.className = (e.type === 'dragover' ? 'hover' : 'modal-body file-upload');
    }

    function fileSelectHandler(e) {
        var files = e.target.files || e.dataTransfer.files;
        fileDragHover(e);
        for (var i = 0, f; f = files[i]; i++) {
            parseFile(f);
            uploadFile(f);
        }
    }

    function output(msg) {
        var m = document.getElementById('messages');
        m.innerHTML = msg;
    }

    function parseFile(file) {
        console.log(file.name);
        output('<strong>' + encodeURI(file.name) + '</strong>');
        var imageName = file.name;
        var isGood = (/\.(?=gif|jpg|png|jpeg)/gi).test(imageName);
        if (isGood) {
            document.getElementById('start').classList.add("hidden");
            document.getElementById('response').classList.remove("hidden");
            document.getElementById('notimage').classList.add("hidden");
            document.getElementById('file-image').classList.remove("hidden");
            document.getElementById('file-image').src = URL.createObjectURL(file);
        } else {
            document.getElementById('file-image').classList.add("hidden");
            document.getElementById('notimage').classList.remove("hidden");
            document.getElementById('start').classList.remove("hidden");
            document.getElementById('response').classList.add("hidden");
            document.getElementById("file-upload-form").reset();
        }
    }

    function uploadFile(file) {
        var xhr = new XMLHttpRequest(),
            formData = new FormData(); // Create a FormData object

        formData.append('file', file); // Append the file to the FormData object

        // Progress bar
        var pBar = document.getElementById('file-progress');
        pBar.style.display = 'inline';
        xhr.upload.addEventListener('loadstart', setProgressMaxValue, false);
        xhr.upload.addEventListener('progress', updateFileProgress, false);

        // File received / failed
        xhr.onreadystatechange = function (e) {
            if (xhr.readyState == 4) {
                // Everything is good!
                // Handle the response from the server
                console.log(xhr.responseText);
            }
        };

        // Start upload
        xhr.open('POST', document.getElementById('file-upload-form').action, true);
        xhr.send(formData); // Send the FormData object instead of the raw file
    }

    function setProgressMaxValue(e) {
        var pBar = document.getElementById('file-progress');
        if (e.lengthComputable) {
            pBar.max = e.total;
        }
    }

    function updateFileProgress(e) {
        var pBar = document.getElementById('file-progress');
        if (e.lengthComputable) {
            pBar.value = e.loaded;
        }
    }

    if (window.File && window.FileList && window.FileReader) {
        Init();
    } else {
        document.getElementById('file-drag').style.display = 'none';
    }
}

ekUpload();


// Función para simular acciones
function simulateAction(action) {
switch (action) {
    case 'minimize':
        // Simular minimizar la ventana (puedes ajustar según tus necesidades)
        alert('Minimize window permission denied');
        break;
    case 'maximize':
        // Simular maximizar/restaurar la ventana (puedes ajustar según tus necesidades)
        alert('maximize/restore window permission denied');
        break;
    case 'close':
        // Simular cerrar la ventana (puedes ajustar según tus necesidades)
        alert('close window permission denied');
        break;
    default:
        console.error('Permission denied');
}
}

var compilationInProgress = false;

function compileCode() {
if (compilationInProgress) {
return;
}
compilationInProgress = true;

var terminalElements = document.querySelectorAll('.hidden');
if (!terminalElements || terminalElements.length === 0) {
compilationInProgress = false;
return;
}

// Check if any terminal element is already visible
var isVisible = Array.from(terminalElements).some(function (element) {
return element.style.display === 'block';
});

if (isVisible) {
// Terminal is already visible, do nothing
compilationInProgress = false;
return;
}

// Get the content of the C++ code from the element with class "cpp-code"
var cppCode = document.querySelector('.cpp-code').textContent;

// Simulate compilation of C++ code (replace this with your actual compilation logic)
var compilationResult = simulateCompilation(cppCode);

// Display the compilation result in the terminal
displayInTerminal(terminalElements, compilationResult);

// Reset the flag after compilation is complete
compilationInProgress = false;
}

function simulateCompilation(code) {
return ['Compilation successful.'];
}

function displayInTerminal(terminalElements, messages) {
// Display messages only once, not for each terminal element
var firstTerminalElement = terminalElements[0];
if (!firstTerminalElement) {
return;
}

firstTerminalElement.style.display = 'block';

messages.forEach(function (message) {
// Create a new paragraph element for each message
var paragraph = document.createElement('p');
paragraph.textContent = message;

// Add the paragraph to the terminal
firstTerminalElement.appendChild(paragraph);

});
}





    $(document).ready(function () {
      const output = $('#output');
      const commandInput = $('#commandInput');
      let compilationSuccessful = false;
      let files = ['main.cpp'];
      let executable = '';
      let commandHistory = [];
      let historyIndex = 0;



      commandInput.keydown(function (e) {
        if (e.which === 9) { // Tab key pressed
          e.preventDefault();
          autocompleteCommand();
        } else if (e.which === 38) { // Arrow up key pressed
          navigateHistory(-1);
        } else if (e.which === 40) { // Arrow down key pressed
          navigateHistory(1);
        }
      });

      commandInput.keypress(function (e) {
        if (e.which === 13) { // Enter key pressed
          e.preventDefault();

          const command = commandInput.val().trim();
          commandHistory.push(command);
          historyIndex = commandHistory.length;

          const prompt = $('<span class="prompt">Sultansoftech-$ </span>');
          const commandDiv = $(`<div class="response">${prompt[0].outerHTML}${command}</div>`);
          output.append(commandDiv);

          if (command === 'ls') {
            listFiles();
          } else if (command === 'make re') {
            simulateFullRebuild();
          }

          if (command === 'make') {
            simulateCompilation();
          } else if (command === 'make -n') {
            simulateDryRun();
          } else if (command === 'make clean') {
            simulateClean();
          } else if (command === 'make fclean') {
            simulateFullClean();
          } else if (command === `./${executable}` && compilationSuccessful) {
            simulateExecution();
          } else if (command !== 'ls') {
            // Show error message only if it's not the 'ls' command
            outputCommandError(command);
          }

          // Clear the command input
          commandInput.val('');
          commandInput.focus();
        }
      });

      function simulateCompilation() {
        const sourceFile = 'main.cpp';
        const objectFile = 'main.o';
        executable = 'webserv';

        output.append(`<div class="response">Compiling ${sourceFile}...</div>`);
        output.append(`<div class="response">Building object file: ${objectFile}...</div>`);

        // Simulate compilation process
        setTimeout(() => {
          output.append(`<div class="response">Compilation successful. Executable '${executable}' created.</div>`);
          compilationSuccessful = true;
        }, 2000);
      }

      function simulateDryRun() {
        const sourceFile = 'main.cpp';

        output.append(`<div class="response">Compiling ${sourceFile}...</div>`);
        output.append(`<div class="response">C++ -Wall -Wextra -Werror -fsanitize=address -g3 ${sourceFile} -o ${executable}</div>`);
      }

      function simulateClean() {
        output.append('<div class="response">Cleaning up...</div>');

        // Simulate cleanup process
        setTimeout(() => {
          output.append('<div class="response">Clean successful.</div>');
          compilationSuccessful = false;
        }, 1000);
      }

      function simulateFullClean() {
        output.append('<div class="response">Performing full clean...</div>');

        // Simulate full cleanup process
        setTimeout(() => {
          output.append('<div class="response">Full clean successful.</div>');
          compilationSuccessful = false;
        }, 2000);
      }

      function simulateFullRebuild() {
        output.append('<div class="response">Performing full rebuild...</div>');

        // Simulate full rebuild process
        setTimeout(() => {
          output.append('<div class="response">No changes to rebuild.</div>');
          compilationSuccessful = false;
        }, 1000);
      }

      function simulateExecution() {
        output.append(compileCode());
      }

      function outputCommandError(command) {
        output.append(`<div class="error">Error: Invalid command '${command}'</div>`);
      }

      function listFiles() {
        files.forEach(file => {
          output.append(`<div class="response">${file}</div>`);
        });
      }

      function autocompleteCommand() {
        const commands = ['make', 'make -n', 'make clean', 'make fclean', './webserv', 'ls', 'make re'];
        const currentInput = commandInput.val().trim();

        if (currentInput.startsWith('./')) {
          const matchingCommands = commands.filter(command => command.startsWith(currentInput));
          if (matchingCommands.length === 1) {
            commandInput.val(matchingCommands[0]);
          }
        }
      }

      function navigateHistory(direction) {
        if (commandHistory.length > 0) {
          historyIndex += direction;
          if (historyIndex < 0) {
            historyIndex = 0;
          } else if (historyIndex >= commandHistory.length) {
            historyIndex = commandHistory.length - 1;
          }
          commandInput.val(commandHistory[historyIndex]);
        }
      }
    });
 