import QtQuick 2.0

Item {
    id:tablero
    width: 400
    height: 400

    signal click(int x, int y, int type)
    signal points(int points)

    property int score: 0
    property int colors: 2 // max:5
    property int size: 4

    GridView {
        id: mainGrid
        cellWidth: 40
        cellHeight: 40
        width: tablero.size * cellWidth
        height: tablero.size * cellHeight
        model: _model
        delegate: myButton

        ListModel {
            id: _model
            function createModel() {
                for (var i = 0; i < tablero.size; i++) {
                    for(var j = 0; j < tablero.size; j++) {
                        _model.append({
                                          "x": i,
                                          "y": j,
                                          "type": Math.floor(Math.random() * tablero.colors),
                                          "selected": false
                                       })
                    }
                }
            }
            Component.onCompleted: {createModel()}
        }

        Component {
            id: myButton
            Item {
                id: item
                width: mainGrid.cellWidth - 2
                height: mainGrid.cellHeight - 2

                Bola {
                    id: bola
                    parent: mainGrid
                    x: item.x; y: item.y;
                    width: item.width; height: item.height;
                    type: _model.get(index).type

                    MouseArea {
                        anchors.fill: parent
                        hoverEnabled: true

                        onClicked: {
                            var myX = _model.get(index).x
                            var myY = _model.get(index).y
                            var type = _model.get(index).type
                            click(myX, myY, type)

                            var resultado = obtenerAdyacentes(myX, myY, type, index)
                            explotar(resultado)
                        }

                        onEntered: {
                            var myX = _model.get(index).x
                            var myY = _model.get(index).y
                            var type = _model.get(index).type

                            var resultado = obtenerAdyacentes(myX, myY, type, index)
                            marcar(resultado.adyacentes)
                        }
                    }
                }
            }
        }
    }

    function explotar(resultado)
    {
        console.log("Explotadas!")
        score = score + Math.pow(2, resultado.puntos - 2)
    }

    function marcar(adyacentes)
    {
        adyacentes.forEach(function(res){
            var e = _model.get(res.index)
            e.visible = false
            e.opacity = 0.5
        })

    }

    function obtenerAdyacentes(x, y, type, index){
        var result = []

        result.push({index: index, objectName: "", x: x, y: y, type: type, selected: true})

        var total = recursion(x, y, type, result)

        for(var i = 0; i < result.length; i++)
        {
            var j = result[i].index
        }

        console.log((total - 1) + " bolas adyacentes")

        return {
            puntos: total,
            adyacentes: result
        }
    }

    function recursion(x, y, type, result)
    {
        var alguna = false

        for(var i = 0; i < _model.count; i++)
        {
            var b = _model.get(i)

            if(type === b.type && esAdyacente(b, x, y))
            {
                if(!contiene(result, b))
                {
                    b.selected = true
                    b.state = "HOVER"
                    b.visible = false
                    b.index = i
                    result.push(b)
                    alguna = true
                }

            }
        }

//            if(alguna)
//            {
//                result.forEach(function(r) {
//                    recursion(r.x, r.y, type)
//                });
//            }

        return result.length
    }

    function esAdyacente(b, x, y)
    {
        var A = Math.abs(b.x - x) === 1 && b.y === y
        var B = Math.abs(b.y - y) === 1 && b.x === x

        return A || B
    }

    function contiene(a, obj) {
        for (var i = 0; i < a.length; i++) {
            if (a[i] === obj) {
                return true;
            }
        }
        return false;
    }
}
