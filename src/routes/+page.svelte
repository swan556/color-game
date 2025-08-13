<script lang="ts">
    // we got a game to create.
    // user will be given an rgb value, and he will have to guess the color based on it. 4 buttons of different colors will be provided and he has to click on the
    // button he thinks is the correct color.
    let ques = $state([0,0,0]);
    let correct_option = $state(0);
    let color_options = $derived([ques, [0,0,0],[0,0,0],[0,0,0]]);
    let score = $state(0);

    const randomInt = ({min, max}: {min: number, max: number}) => {
        return Math.floor(Math.random() * (max - min + 1)) + min;
    }

    const randomChoice = ({arr}: {arr: Array<number>}) => {
        let n: number = arr.length;
        return arr[randomInt({min: 0,max: n-1})];
    }
    
    const randomColor =  () => {
        let rc = [randomInt({min:0, max:255}), randomInt({min:0, max:255}),randomInt({min:0, max:255})];
        return rc;
    }

    const nextColor = () => {

        let simple_values = [0, 255];
        let randomInt1 = randomInt({min: 0,max: 255});
        let randomInt2 = randomInt({min: 0,max: 255});
        let randomInt3 = randomInt({min: 0,max: 255});

        ques = [
            randomChoice({arr: [randomChoice({arr: simple_values}), randomInt1]}),
            randomChoice({arr: [randomChoice({arr: simple_values}), randomInt2]}),
            randomChoice({arr: [randomChoice({arr: simple_values}), randomInt3]})
        ]

        let C1 = randomColor();
        let C2 = randomColor();
        let C3 = randomColor();

        color_options = [
            ques, C1, C2, C3
        ]

        let n:number = 4;

        correct_option = 0;
        for(let i = n-1; i>0; i--) {
            let j = Math.floor(Math.random()*(i+1));
            [color_options[i], color_options[j]] = [color_options[j], color_options[i]];
            if(j === correct_option) {correct_option = i;}
        }
    }

    const check_option = ({id_}: {id_: string}) => {
        if(id_ === String(ques)) {
            score++;
        }
    }

</script>

<div class="container">
    <span class="rgbPicker">rgb({ques}): correct ans is: {correct_option}</span>

    <div class="options">

        {#each color_options as color}
            <button style="background-color: rgb({color})" id="{String(color)}" onclick={() => check_option({id_: String(color)})}>
                .
            </button>
        {/each}
    </div>

    <button class="nextLevel" onclick={nextColor} style="background-color: rgb({ques})">Next</button>
    <span class="score">score: {score}</span>
</div>

<style>
    .container {
        display: flex;
        flex-direction: column;
        align-items: center;
    }

    .nextLevel {
        width: 100px;
        align-self: right 30px;
    }

    .score {
        size: 300%;
    }
</style>
