import React, { useState } from "react";
import "../styles/grid.css";

const Grid = () => {
    const [toggle, setToggle] = useState(false);
    const [state, setState] = useState({
        start: 1,
        end: 45,
    });
    const [time, setTime] = useState("");
    const [walls, setWalls] = useState(new Array(46).fill(0));

    function show() {
        setToggle(true);
    }
    function reset() {
        setWalls(new Array(46).fill(0));
        for (let i = 1; i <= 45; i++) {
            var cell = document.getElementById(i);
            cell.style.backgroundColor = "";
        }
        setTime("");
    }
    function delay(ms) {
        return new Promise(resolve => setTimeout(resolve, ms));
    }
    async function bfs() {
        setTime("");
        var vis = new Array(46).fill(0);
        for (let i = 1; i <= 45; i++) {
            var cell = document.getElementById(i);
            if (!walls[i]) cell.style.backgroundColor = "";
        }
        var q = {
            x: [],
            path: []
        }
        q.x.push(parseInt(state.start));
        let tmp_path = [parseInt(state.start)];
        q.path.push(tmp_path);
        vis[parseInt(state.start)] = 1;

        if (parseInt(state.start) > 45) {
            alert("Invalid input");
            return;
        }

        let ans = [];
        while (q.x.length > 0) {
            var node = q.x.shift();
            const path = q.path.shift();

            if (node === parseInt(state.end)) {
                var cell = document.getElementById(node);
                cell.style.backgroundColor = "red";
                ans = path;
                break;
            }
            else {
                var cell = document.getElementById(node);
                cell.style.backgroundColor = "yellow";
            }

            await delay(100);
            // up
            if (node - 9 > 0 && vis[node - 9] === 0 && !walls[node - 9]) {
                q.x.push(node - 9);
                vis[node - 9] = 1;
                let tmp = [...path];
                tmp.push(node - 9);
                q.path.push(tmp);
            }
            // down
            if (node + 9 <= 45 && vis[node + 9] === 0 && !walls[node + 9]) {
                q.x.push(node + 9);
                vis[node + 9] = 1;
                let tmp1 = [...path];
                tmp1.push(node + 9);
                q.path.push(tmp1);
            }
            // left
            if ((node - 1) % 9 != 0 && node - 1 > 0 && vis[node - 1] === 0 && !walls[node - 1]) {
                q.x.push(node - 1);
                vis[node - 1] = 1;
                let tmp2 = [...path];
                tmp2.push(node - 1);
                q.path.push(tmp2);
            }
            // right
            if (node % 9 != 0 && node + 1 <= 46 && vis[node + 1] === 0 && !walls[node + 1]) {
                q.x.push(node + 1);
                vis[node + 1] = 1;
                let tmp3 = [...path];
                tmp3.push(node + 1);
                q.path.push(tmp3);
            }

        }
        console.log(ans);
        if (ans.length === 0) {
            setTime("Path not found");
        }
        else {
            for (let i = 0; i < ans.length; i++) {
                var cell = document.getElementById(ans[i]);
                cell.style.backgroundColor = "green";
                await delay(200);
            }
            setTime(`Time taken = ${ans.length - 1}`);
        }
    }
    function handle(e) {
        const n = { ...state };
        n[e.target.name] = e.target.value;
        setState(n);
    }
    function wall(e) {
        let cell = e.target.id;
        if (walls[cell]) {
            walls[cell] = 0;
            var x = document.getElementById(cell);
            x.style.backgroundColor = "";
        }
        else {
            walls[cell] = 1;
            var x = document.getElementById(cell);
            x.style.backgroundColor = "black";
        }
    }
    return (
        <>
            <div class="game">
                <div>
                    <table>
                        <tr>
                            <td id="1" onClick={(e) => wall(e)}>1</td>
                            <td id="2" onClick={(e) => wall(e)}>2</td>
                            <td id="3" onClick={(e) => wall(e)}>3</td>
                            <td id="4" onClick={(e) => wall(e)}>4</td>
                            <td id="5" onClick={(e) => wall(e)}>5</td>
                            <td id="6" onClick={(e) => wall(e)}>6</td>
                            <td id="7" onClick={(e) => wall(e)}>7</td>
                            <td id="8" onClick={(e) => wall(e)}>8</td>
                            <td id="9" onClick={(e) => wall(e)}>9</td>
                        </tr>
                        <tr>
                            <td id="10" onClick={(e) => wall(e)}>10</td>
                            <td id="11" onClick={(e) => wall(e)}>11</td>
                            <td id="12" onClick={(e) => wall(e)}>12</td>
                            <td id="13" onClick={(e) => wall(e)}>13</td>
                            <td id="14" onClick={(e) => wall(e)}>14</td>
                            <td id="15" onClick={(e) => wall(e)}>15</td>
                            <td id="16" onClick={(e) => wall(e)}>16</td>
                            <td id="17" onClick={(e) => wall(e)}>17</td>
                            <td id="18" onClick={(e) => wall(e)}>18</td>
                        </tr>
                        <tr>
                            <td id="19" onClick={(e) => wall(e)}>19</td>
                            <td id="20" onClick={(e) => wall(e)}>20</td>
                            <td id="21" onClick={(e) => wall(e)}>21</td>
                            <td id="22" onClick={(e) => wall(e)}>22</td>
                            <td id="23" onClick={(e) => wall(e)}>23</td>
                            <td id="24" onClick={(e) => wall(e)}>24</td>
                            <td id="25" onClick={(e) => wall(e)}>25</td>
                            <td id="26" onClick={(e) => wall(e)}>26</td>
                            <td id="27" onClick={(e) => wall(e)}>27</td>
                        </tr>
                        <tr>
                            <td id="28" onClick={(e) => wall(e)}>28</td>
                            <td id="29" onClick={(e) => wall(e)}>29</td>
                            <td id="30" onClick={(e) => wall(e)}>30</td>
                            <td id="31" onClick={(e) => wall(e)}>31</td>
                            <td id="32" onClick={(e) => wall(e)}>32</td>
                            <td id="33" onClick={(e) => wall(e)}>33</td>
                            <td id="34" onClick={(e) => wall(e)}>34</td>
                            <td id="35" onClick={(e) => wall(e)}>35</td>
                            <td id="36" onClick={(e) => wall(e)}>36</td>
                        </tr>
                        <tr>
                            <td id="37" onClick={(e) => wall(e)}>37</td>
                            <td id="38" onClick={(e) => wall(e)}>38</td>
                            <td id="39" onClick={(e) => wall(e)}>39</td>
                            <td id="40" onClick={(e) => wall(e)}>40</td>
                            <td id="41" onClick={(e) => wall(e)}>41</td>
                            <td id="42" onClick={(e) => wall(e)}>42</td>
                            <td id="43" onClick={(e) => wall(e)}>43</td>
                            <td id="44" onClick={(e) => wall(e)}>44</td>
                            <td id="45" onClick={(e) => wall(e)}>45</td>
                        </tr>
                    </table>
                </div>

                <div>
                    {/* <div class="conf" style={{ "display": !toggle ? "none" : "block" }}> */}
                    <div class="conf">
                        <input type="text" name="start" onChange={(e) => handle(e)} placeholder="Start" />
                        <input type="text" name="end" onChange={(e) => handle(e)} placeholder="End" />
                        <input type="button" value="BFS" onClick={bfs} />
                    </div>
                    <input type="button" value="Reset" onClick={reset} />
                </div>
            </div>
            {time}
        </>
    )
}

export default Grid;