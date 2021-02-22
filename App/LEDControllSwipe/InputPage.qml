import QtQuick 2.0
import QtQuick.Controls 2.2

import InputItem 1.0

Page {
    Connections { // das signal abgreifen!!!!!! geil!
        target: inputItem
        onNameUpdated: {
            console.log("DataChanged")
        }
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
        x: 66
        y: 136
        text: qsTr("5")
        onCheckedChanged: {
            if(checked) inputItem.appendObject(5)
            else console.log("Unchecked")
        }
    }

    CheckBox {
        id: checkBox1
        x: 66
        y: 182
        text: qsTr("7")
    }

    Tumbler {
        id: tumbler
        x: 230
        y: 56
        model: 10
        onCurrentIndexChanged: inputItem.age = currentIndex
    }

}
