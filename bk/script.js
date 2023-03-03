function getUserInput() {
    var userInput = alert("Please type in the input bar or use the microphone for audio input",);
}

    let output_a = document.getElementById("output");

function showOutput() {
    let input_a = document.getElementById("input").value;
    if (input_a == "") {
        output_a.style.display = "none";
    } else {
        output_a.style.display = "block";
    }
}

        const record = document.getElementById("record-button");
        const stopRecord = document.getElementById("stop-record");

        navigator.mediaDevices.getUserMedia({audio: true}).then(stream => {
        handlerFunction(stream)})

    const form = document.querySelector('form');
    form.addEventListener('submit', (e) => {
    e.preventDefault();
    const input = document.querySelector('#input').value;
    fetch('/symptom-checker?input=' + input).then(response => response.json()).then(data => {
        let diagnosis = "";
        diagnosis = data.response;
        const output = document.querySelector('#output');
        output.innerHTML = `<p>${diagnosis}</p>`;
        diagnosis = "";
    });
});

        let rec;

        function handlerFunction(stream) {
        rec = new MediaRecorder(stream);
        rec.ondataavailable = e => {
        audioChunks.push(e.data);
        if (rec.state == "inactive") {
            let blob = new Blob(audioChunks, {type: 'audio/mpeg-3'});
            //        recordedAudio.src =URL.createObjectURL(blob);
            //      recordedAudio.controls=true;
            //    recordedAudio.autoplay=true;
            sendData(blob)
            }
            }  
        }

        function sendData(blob) {
        const formA = new FormData();
        formA.append("audio_file", blob);
        // const input = document.querySelector('#input').value;
        fetch('/to_whisper', {
            method: 'POST',
            body: formA
     }).then(response => response.json()).then(data => {
        let diagnosis = "";
        diagnosis = data.response;
        const output = document.querySelector('#output');
        output.innerHTML = `<p>${diagnosis}</p>`;
        diagnosis = "";
        });
    }

function flash(message, duration) {
    const alertEl = document.createElement('div');
    alertEl.classList.add('alert');
    alertEl.textContent = message;
    document.body.appendChild(alertEl);
    setTimeout(() => {
        alertEl.remove();
    }, duration);
}


    stopRecord.disabled = true;
    stopRecord.style.backgroundColor = "brown";
    stopRecord.style.color = "white";

    record.onclick = e => {
    console.log("record button clicked");
     record.disabled = true;
     stopRecord.disabled = false;
     audioChunks = [];
     rec.start();
      alert("You started recording, click the stop button when you're done", 2000);
        output_a.style.display = "block";
}

    stopRecord.onclick = e => {
    console.log("stop button clicked")
     record.disabled = false;
     rec.stop();
 }
