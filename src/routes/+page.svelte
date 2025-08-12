<script lang="ts">

    // we got a game to create.
    // user will be given an rgb value, and he will have to guess the color based on it. 4 buttons of different colors will be provided and he has to click on the
    // button he thinks is the correct color.
    let ques = $state([0,0,0]);

    const randomInt = ({min, max}: {min: number, max: number}) => {
        return Math.floor(Math.random() * (max - min + 1)) + min;
    }

    const randomChoice = ({arr}: {arr: Array<number>}) => {
        let n: number = arr.length;
        return arr[randomInt({min: 0,max: n-1})];
    }

    
    const random_color =  () => {
        let rc = [randomInt({min:0, max:255}), randomInt({min:0, max:255}),randomInt({min:0, max:255})];
        return rc;
    }

    

    let color_options = $derived([ques, random_color(), random_color(), random_color()]);

    const next_color = () => {

        let simple_values = [0, 255];
        let randomInt1 = randomInt({min: 0,max: 255});
        let randomInt2 = randomInt({min: 0,max: 255});
        let randomInt3 = randomInt({min: 0,max: 255});

        ques = [
            randomChoice({arr: [randomChoice({arr: simple_values}), randomInt1]}),
            randomChoice({arr: [randomChoice({arr: simple_values}), randomInt2]}),
            randomChoice({arr: [randomChoice({arr: simple_values}), randomInt3]})
        ]
        
    }
</script>

<div class="container">
    <span class="rgbPicker">rgb({ques})</span>

    <div class="options">

        {#each color_options as color}
            <button style="background-color: rgb({color})">
                .
            </button>
        {/each}
    </div>

    <button class="nextLevel" onclick={next_color}>Next</button>
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
</style>