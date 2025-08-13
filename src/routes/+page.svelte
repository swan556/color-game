<script lang="ts">
	// we got a game to create.
	// user will be given an rgb value, and he will have to guess the color based on it. 4 buttons of different colors will be provided and he has to click on the
	// button he thinks is the correct color.
	let ques = $state([0, 0, 0]);
	let correct_option = $state(0);
	let color_options = $derived([ques, [0, 0, 0], [0, 0, 0], [0, 0, 0]]);
	let score = $state(0);
	let checked = $state(false);
	let selected = $state('-1,-1,-1');
	let start = $state(false);

	const randomInt = ({ min, max }: { min: number; max: number }) => {
		return Math.floor(Math.random() * (max - min + 1)) + min;
	};

	const randomChoice = ({ arr }: { arr: Array<number> }) => {
		let n: number = arr.length;
		return arr[randomInt({ min: 0, max: n - 1 })];
	};

	const randomColor = () => {
		let rc = [
			randomInt({ min: 0, max: 255 }),
			randomInt({ min: 0, max: 255 }),
			randomInt({ min: 0, max: 255 })
		];
		return rc;
	};

	const nextColor = () => {
		if (selected === '-1,-1,-1') return;

		if (selected === String(ques)) {
			score++;
		}

		selected = '-1,-1,-1';

		let simple_values = [0, 255];
		let randomInt1 = randomInt({ min: 0, max: 255 });
		let randomInt2 = randomInt({ min: 0, max: 255 });
		let randomInt3 = randomInt({ min: 0, max: 255 });

		ques = [
			randomChoice({ arr: [randomChoice({ arr: simple_values }), randomInt1] }),
			randomChoice({ arr: [randomChoice({ arr: simple_values }), randomInt2] }),
			randomChoice({ arr: [randomChoice({ arr: simple_values }), randomInt3] })
		];

		let C1 = randomColor();
		let C2 = randomColor();
		let C3 = randomColor();

		color_options = [ques, C1, C2, C3];

		let n: number = 4;

		correct_option = 0;
		for (let i = n - 1; i > 0; i--) {
			let j = Math.floor(Math.random() * (i + 1));
			[color_options[i], color_options[j]] = [color_options[j], color_options[i]];
			if (j === correct_option) {
				correct_option = i;
			}
		}
		checked = false;
	};

	const check_option = ({ id_ }: { id_: string }) => {
		if (selected != '-1,-1,-1' && id_ === selected) {
			selected = '-1,-1,-1';
		} else {
			selected = id_;
		}
	};

	const startGame = () => {
		start = true;

		let simple_values = [0, 255];
		let randomInt1 = randomInt({ min: 0, max: 255 });
		let randomInt2 = randomInt({ min: 0, max: 255 });
		let randomInt3 = randomInt({ min: 0, max: 255 });

		ques = [
			randomChoice({ arr: [randomChoice({ arr: simple_values }), randomInt1] }),
			randomChoice({ arr: [randomChoice({ arr: simple_values }), randomInt2] }),
			randomChoice({ arr: [randomChoice({ arr: simple_values }), randomInt3] })
		];

		let C1 = randomColor();
		let C2 = randomColor();
		let C3 = randomColor();

		color_options = [ques, C1, C2, C3];

		let n: number = 4;

		correct_option = 0;
		for (let i = n - 1; i > 0; i--) {
			let j = Math.floor(Math.random() * (i + 1));
			[color_options[i], color_options[j]] = [color_options[j], color_options[i]];
			if (j === correct_option) {
				correct_option = i;
			}
		}
		checked = false;
	};
</script>

<div class="app">
    <div class="container">
        {#if !start}
            <button onclick={startGame} style="height: 100px; width: 400px; font-size: 400%; border-radius: 20%; background: linear-gradient(to bottom, #d12828, #d95f5f); outline: none; color: #ffffff">Start</button>
        {:else}
            <div class="rgbPicker">rgb({ques})</div>

            <div class="options ">
                {#each color_options as color}
                    <button
                        style="background-color: rgb({color}); font-size: 200%; height: 10rem; aspect-ratio: 1/1; border-radius: 20%; outline: none;color: #ffffff"
                        id={String(color)}
                        onclick={() => check_option({ id_: String(color) })}
                        class:active={checked}
                    >
                        {String(color) === selected ? 'O' : 'X'}
                    </button>
                {/each}
            </div>

            <button class="nextLevel" onclick={nextColor}>Next</button>
            <!-- style="background-color: rgb({ques})"> -->
            <span class="score">score: {score}</span>{/if}
    </div>
</div>

<style>

    .app {
        height: 100vh;
		background: url("/bg1.jpeg");
		background-repeat: no-repeat;
		background-position: center;
		background-size: cover;

		display: flex;
		justify-content: center;
		align-items: center;
    }

	.container {
		display: flex;
		flex-direction: column;
		align-items: center;
        gap: 0.75rem;
        max-width: 248px;
        margin-inline: auto;
        height: 100vh;
        justify-content: center;
	}

    .rgbPicker {
        margin-bottom: 5rem;
        font-size: 300%;
        color: rgb(66, 66, 66);
        font-weight: 900;
        border-radius: 20%;
        background-color: transparent;
    }

	.nextLevel {
		width: 300%;
		align-self: right 30px;
        margin-top: 10rem;
        height: 90px;
        align-items: center;
        font-size: 300%;
        background-color: beige;
        outline: none;
        border-radius: 10%;


	}

	.score {
        margin-top: 1rem;
		font-size: 300%;
        color: red;
	}

    .options {
        display: flex;
        gap: 1rem;
    }
</style>
