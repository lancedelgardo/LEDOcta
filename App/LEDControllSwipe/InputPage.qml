import QtQuick 2.9
import QtQuick.Controls 2.2

import InputItem 1.0

Page {
    Connections { // das signal abgreifen!!!!!! geil!
        target: inputItem
        onNameUpdated: {
            console.log("DataChanged")
        }
        onTimerEnded: {
            busyIndicator.visible = false
            busyIndicator.running = false
        }
    }

    background: Rectangle{
        anchors.fill: parent
        color: "lightgrey"
    }

    TextEdit {
        id: textEdit
        x: 66
        y: 40
        width: 224
        height: 63
        text: inputItem.name // vom c++ ablesen und aktuelle änderungen bekommen wenn signal ausgelöst wird
        font.pixelSize: 12
        onTextChanged: inputItem.name = text // zu c++ schicken
    }

    CheckBox {
        id: checkBox
        x: 14
        y: 76
        text: qsTr("5")
        onCheckedChanged: {
            if(checked) inputItem.appendObject(5)
            else console.log("Unchecked")
        }
    }

    CheckBox {
        id: checkBox1
        x: 14
        y: 141
        text: qsTr("7")
    }

    Tumbler {
        id: tumbler
        x: 143
        y: 93
        model: 10
        onCurrentIndexChanged: inputItem.age = currentIndex
    }

    BusyIndicator {
        id: busyIndicator
        x: 39
        y: 249
        clip: false
        visible: false
        running: false
    }

    Button {
        id: button
        x: 14
        y: 187
        text: qsTr("StartTimer")
        onClicked: {
            inputItem.onTimerStart()
            busyIndicator.visible = true
            busyIndicator.running = true
        }
    }



    eBorderImage {
        id: borderImage
        x: 366
        y: 143
        width: 100
        height: 100
        source: "home/tanja/Schreibtisch/Bildschirmfoto_2021-02-22_10-27-42.png"

        MouseArea {
            anchors.fill: parent
            onClicked: console.log("Bild geklickt");
        }
    }

}
